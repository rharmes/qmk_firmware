#!/usr/bin/env python3
"""Build a clangd compile_commands.json covering all of Ross's handwired boards.

`qmk compile --compiledb` writes a database for one keyboard, cleans `.build`
first, and never lists keymap.c (modern QMK compiles it by #include from
quantum/keymap_introspection.c). clangd then guesses flags for keymap.c from
whichever file is nearest, which is the wrong board for all but one keymap.

This script runs the generator per board, clones each board's
keymap_introspection.c record for its keymap.c, merges the databases (first
board wins for shared files), then rebuilds every board so the generated
`.build/obj_*/src/default_keyboard.h` headers the database points at exist.

Usage, from the repo root:   util/rharmes/compiledb.py [board ...]
"""
import copy
import json
import subprocess
import sys
from pathlib import Path

BOARDS = ["am37", "am49", "am96", "zf65", "vc3"]
ROOT = Path(__file__).resolve().parents[2]
DB = ROOT / "compile_commands.json"


def qmk_compile(board: str, *extra: str) -> None:
    subprocess.run(["qmk", "compile", "-kb", f"handwired/{board}", "-km", "default", *extra], cwd=ROOT, check=True)


def main(boards: list[str]) -> None:
    per_board = {}
    for board in boards:
        qmk_compile(board, "--compiledb")
        per_board[board] = json.loads(DB.read_text())

    seen, merged = set(), []
    for board, records in per_board.items():
        intro = next(r for r in records if r["file"] == "quantum/keymap_introspection.c")
        keymap = copy.deepcopy(intro)
        keymap["file"] = f"keyboards/handwired/{board}/keymaps/default/keymap.c"
        for record in [keymap, *records]:
            if record["file"] not in seen:
                seen.add(record["file"])
                merged.append(record)
    DB.write_text(json.dumps(merged, indent=4))
    print(f"wrote {DB} with {len(merged)} entries for {', '.join(boards)}")

    # --compiledb cleans .build, so only the last board's generated headers survive.
    for board in boards[:-1]:
        qmk_compile(board)


if __name__ == "__main__":
    main(sys.argv[1:] or BOARDS)
