# rharmes/qmk_firmware

A fork of [qmk/qmk_firmware](https://github.com/qmk/qmk_firmware) that exists to hold
Ross's handwired boards under `keyboards/handwired/`: `am37`, `am49`, `am96`, `zf65`,
`vc3`. Nothing else in the tree is ours. `~/.claude/CLAUDE.md` holds the working defaults;
this file holds the exceptions and the build workflow.

## Branches

- **`master` is upstream `master`, unmodified.** Sync it on GitHub with
  `gh repo sync rharmes/qmk_firmware --source qmk/qmk_firmware --branch master` (needs the
  `workflow` token scope), then `git fetch origin` and fast-forward. Never commit to it.
- **Work on a branch off `master`** and land it with a PR. The boards are the only
  files any branch should touch, plus this file.
- **`dev` is frozen.** It is the QMK 0.9.46-era tree the boards ran on until September
  2026, tagged `legacy-0.9.46`. See *Legacy firmware* below.
- **Tasks live in this repo's GitHub Issues**, referenced as `#n`.

## Building and flashing

Toolchain is upstream's macOS setup: `brew install qmk/qmk/qmk` plus force-linked
`avr-gcc@8`, `arm-none-eabi-gcc@8` and `arm-none-eabi-binutils`. `qmk doctor` must be
clean before blaming a board. The `qmk` CLI only works inside a modern checkout; run in the
legacy tree it dies with `conflicting subparser: config`.

    qmk compile -kb handwired/am37 -km default
    qmk flash   -kb handwired/am37 -km default    # waits for the bootloader

All boards are `atmega32u4`. `am37`, `am49`, `am96` and `zf65` use `qmk-dfu`; `vc3` uses
`caterina`. Flashing a `qmk-dfu` board by hand needs `dfu-programmer atmega32u4 erase
--force` first, or `flash` fails with `Memory write error`.

clangd: generate `compile_commands.json` with
`qmk generate-compilation-database -kb handwired/<board> -km default`; it and `.clangd`
stay in `.git/info/exclude`, never committed.

## Legacy firmware

The tag `legacy-0.9.46` (commit `b8adf11a45`) is the last pre-port tree and still builds
with the same `avr-gcc@8`:

    git checkout legacy-0.9.46
    export PATH="/opt/homebrew/opt/avr-gcc@8/bin:$PATH"
    make handwired/<board>:default

The `.hex` files built from that tag on 2026-09-20 are kept outside the repo in
`~/Developer/qmk-legacy-firmware/`, with flashing notes in its README.
