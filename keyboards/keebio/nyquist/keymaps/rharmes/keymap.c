/* Copyright 2020 Ross Harmes <ross@rossharmes.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#define _ARROWS 1
#define _NAV 2
#define _RECT 3
=======
#define _LOWER 1
#define _RAISE 2
>>>>>>> Initial commit of my Nyquist keymap, based on my current Ergodox layout: https://configure.ergodox-ez.com/ergodox-ez/layouts/qn5G5/latest/0
=======
#define _ARROWS 1
#define _NAV 2
#define _RECT 3
>>>>>>> Adjusted the keys for triggering the layers, and added another layer for scrolling.
=======
#define _ARROWS 1
#define _NAV 2
#define _RECT 3
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830

// Layers and mods
#define SPC_GUI LGUI_T(KC_SPC)            // ⌘ when held, Sapce when tapped
#define ENT_GUI RGUI_T(KC_ENT)            // ⌘ when held, Enter when tapped
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#define ARW_F LT(_ARROWS, KC_F)           // Momentarily activate layer 1 when held, and F when tapped
#define NAV_J LT(_NAV, KC_J)              // Momentarily activate layer 2 when held, and J when tapped
#define RECT MO(_RECT)                    // Momentarily activate layer 3

// Shortcuts
#define LOCK LCTL(LGUI(KC_Q))             // ⌘^Q: Lock screen
=======
#define LWR_ESC LT(_LOWER, KC_ESC)        // Momentarily activate layer 1 when held, and Escape when tapped
#define RSE MO(_RAISE)                    // Momentarily activate layer 2

// Shortcuts
#define LOCK LCTL(LGUI(KC_Q))             // ⌘^Q: Lock screen
#define UNDO LGUI(KC_Z)                   // ⌘Z: Undo
>>>>>>> Initial commit of my Nyquist keymap, based on my current Ergodox layout: https://configure.ergodox-ez.com/ergodox-ez/layouts/qn5G5/latest/0
=======
=======
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
#define ARW_F LT(_ARROWS, KC_F)           // Momentarily activate layer 1 when held, and F when tapped
#define NAV_J LT(_NAV, KC_J)              // Momentarily activate layer 2 when held, and J when tapped
#define RECT_BS LT(_RECT, KC_BSPC)        // Momentarily activate layer 3 when held, and backspace when tapped

// Shortcuts
#define LOCK LCTL(LGUI(KC_Q))             // ⌘^Q: Lock screen
<<<<<<< HEAD
>>>>>>> Adjusted the keys for triggering the layers, and added another layer for scrolling.
=======
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
#define CUT LGUI(KC_X)                    // ⌘X: Cut
#define COPY LGUI(KC_C)                   // ⌘C: Copy
#define PASTE LGUI(KC_V)                  // ⌘C: Paste
#define PRV_WD RALT(RSFT(KC_LEFT))        // ⇧⌥←: Select to the beginning of the previous word
#define NXT_WD RALT(RSFT(KC_RGHT))        // ⇧⌥→: Select to the end of the next word
#define LN_SRT RCTL(KC_A)                 // ^A: Move to the beginning of the line or paragraph
#define LN_END RCTL(KC_E)                 // ^E: Move to the end of a line or paragraph
#define DEL_RT RCTL(KC_D)                 // ^D: Delete the character to the right of the insertion point
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#define KILL_LN RCTL(KC_K)                // ^K: Kill line
=======
>>>>>>> Initial commit of my Nyquist keymap, based on my current Ergodox layout: https://configure.ergodox-ez.com/ergodox-ez/layouts/qn5G5/latest/0
=======
#define KILL_LN RCTL(KC_K)                // ^K: Kill line
>>>>>>> Add shortcut to delete line, as well as Home and End keys.
=======
#define KILL_LN RCTL(KC_K)                // ^K: Kill line
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
#define GUI_BL RGUI(KC_LBRC)              // ⌘[: Previous Channel in Slack
#define GUI_BR RGUI(KC_RBRC)              // ⌘]: Next Channel in Slack

// Rectangle (https://rectangleapp.com/) shortcuts for window management
#define PRV_DIS RALT(RCTL(RGUI(KC_LEFT))) // ^⌥⌘←: Move current window to previous display
#define NXT_DIS RALT(RCTL(RGUI(KC_RGHT))) // ^⌥⌘→: Move current window to next display
#define FULLSCR RALT(RGUI(KC_F))          // ⌥⌘F: Expand current window to fill the display
#define UP_HALF RALT(RGUI(KC_UP))         // ⌥⌘↑: Move current window to fill the upper half of the display
#define LW_HALF RALT(RGUI(KC_DOWN))       // ⌥⌘↓: Move current window to fill the lower half of the display
#define LF_HALF RALT(RGUI(KC_LEFT))       // ⌥⌘←: Move current window to fill the left half of the display
#define RT_HALF RALT(RGUI(KC_RGHT))       // ⌥⌘→: Move current window to fill the right half of the display
#define UP_LEFT RCTL(RGUI(KC_LEFT))       // ^⌘←: Move current window to fill the upper-left quadrant
#define UP_RGHT RCTL(RGUI(KC_RGHT))       // ^⌘→: Move current window to fill the upper-right quadrant
#define LW_LEFT RSFT(RCTL(RGUI(KC_LEFT))) // ⇧^⌘←: Move current window to fill the lower-left quadrant
#define LW_RGHT RSFT(RCTL(RGUI(KC_RGHT))) // ⇧^⌘→: Move current window to fill the lower-right quadrant

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
/* QWERTY (yellow underglow)
=======
/* QWERTY
>>>>>>> Initial commit of my Nyquist keymap, based on my current Ergodox layout: https://configure.ergodox-ez.com/ergodox-ez/layouts/qn5G5/latest/0
=======
/* QWERTY (yellow underglow)
>>>>>>> Added support for lighting layers.
=======
/* QWERTY (yellow underglow)
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
 * .-----------------------------------------.     .-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |  BS  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
 * |  BS  |   A  |   S  |   D  |  (F) |   G  |     |   H  |  (J) |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lock |      | LCtrl| LAlt |  Esc |  Spc |     |  Ent | RECT |   [  |   ]  |   -  |   =  |
=======
 * |  BS  |   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lock |      | LCtrl| LAlt |  LWR |  Spc |     |  Ent |  RSE |   [  |   ]  |   -  |   =  |
>>>>>>> Initial commit of my Nyquist keymap, based on my current Ergodox layout: https://configure.ergodox-ez.com/ergodox-ez/layouts/qn5G5/latest/0
=======
 * |  BS  |   A  |   S  |   D  |  (F) |   G  |     |   H  |  (J) |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lock |      | LCtrl| LAlt |  Esc |  Spc |     |  Ent | RECT |   [  |   ]  |   -  |   =  |
>>>>>>> Adjusted the keys for triggering the layers, and added another layer for scrolling.
=======
=======
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
 * |  BS  |   A  |   S  |   D  | F(1) |   G  |     |   H  | J(2) |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lock |      | LCtrl| LAlt |  Esc |  Spc |     |  Ent | BS(3)|   [  |   ]  |   -  |   =  |
<<<<<<< HEAD
>>>>>>> Added a third backspace, on the layer 3 mod.
 * `-----------------------------------------'     '-----------------------------------------'
 */
<<<<<<< HEAD
[_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH, \
<<<<<<< HEAD
<<<<<<< HEAD
  KC_BSPC,  KC_A,    KC_S,    KC_D,    ARW_F,   KC_G,    KC_H,    NAV_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  LOCK,     XXXXXXX, KC_LCTL, KC_LALT, KC_ESC,  SPC_GUI, ENT_GUI, RECT,    KC_LBRC, KC_RBRC, KC_MINS, KC_EQL \
=======
=======
 * `-----------------------------------------'     '-----------------------------------------'
 */
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH,
  KC_BSPC,  KC_A,    KC_S,    KC_D,    ARW_F,   KC_G,    KC_H,    NAV_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
<<<<<<< HEAD
<<<<<<< HEAD
  LOCK,     XXXXXXX, KC_LCTL, KC_LALT, KC_ESC,  SPC_GUI, ENT_GUI, RECT,    KC_LBRC, KC_RBRC, KC_MINS, KC_EQL
>>>>>>> Remove unnecessary trailing backslashes in the LAYOUT blocks,
=======
  LOCK,     XXXXXXX, KC_LCTL, KC_LALT, KC_ESC,  SPC_GUI, ENT_GUI, RECT_BS, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL
>>>>>>> Added a third backspace, on the layer 3 mod.
=======
  LOCK,     XXXXXXX, KC_LCTL, KC_LALT, KC_ESC,  SPC_GUI, ENT_GUI, RECT_BS, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
),

/* ARROWS (blue underglow) - Cursor movement, media keys, and clipboard shortcuts
 * .-----------------------------------------.     .-----------------------------------------.
 * |      |      |      |      |      |      |     | Mute | Vol- | Vol+ |   -  |   =  |  BS  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  Tab |      |      |      |      |      |     |      | PvWd |  Up  | NxWd |      | DelR |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  BS  |      |      |      |(Held)|      |     | LSrt | Left | Down | Right| LEnd | Kill |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft|      |      |      |      |      |     |   =  |  Cut | Copy | Paste|      |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      | LCtrl| LAlt |  Esc |  Spc |     |  Ent | BS(3)|GUI-[ |GUI-] | RGB T|Reset |
 * `-----------------------------------------'     '-----------------------------------------'
 */
[_ARROWS] = LAYOUT(
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_MINS, KC_EQL,  _______,
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, PRV_WD,  KC_UP,   NXT_WD,  XXXXXXX, DEL_RT,
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, LN_SRT,  KC_LEFT, KC_DOWN, KC_RGHT, LN_END,  KILL_LN,
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  CUT,     COPY,    PASTE,   XXXXXXX, _______,
  XXXXXXX,  XXXXXXX, _______, _______, _______, _______, _______, _______, GUI_BL,  GUI_BR,  RGB_TOG, RESET
),

/* NAV (red underglow) - Navigation shortcuts and media keys
 * .-----------------------------------------.     .-----------------------------------------.
 * |  Esc |   B- |   B+ | Prev | Play | Next |     |      |      |      |      |      |  BS  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  Tab |      | Home | WhDn | End  | PgUp |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  BS  |      | WhRt | WhUp | WhLf | PgDn |     |      |(Held)|      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft|      |      |      |      |   -  |     |      |      |      |      |      |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Reset|      | LCtrl| LAlt |  Esc |  Spc |     |  Ent | BS(3)|      |      |      |      |
 * `-----------------------------------------'     '-----------------------------------------'
 */
[_NAV] = LAYOUT(
  KC_ESC,   KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______,  XXXXXXX, KC_HOME, KC_WH_D, KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,  XXXXXXX, KC_WH_R, KC_WH_U, KC_WH_L, KC_PGDN, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  RESET,    XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* RECT (lavender underglow) - Window management shortcuts for Rectangle
 * .-----------------------------------------.     .-----------------------------------------.
 * |      | Hue+ | Sat+ | Val+ | Plain| RGB T|     |      |      |      |      |      |  BS  |
<<<<<<< HEAD
=======
  KC_BSPC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
=======
  KC_BSPC,  KC_A,    KC_S,    KC_D,    ARW_F,   KC_G,    KC_H,    NAV_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
>>>>>>> Adjusted the keys for triggering the layers, and added another layer for scrolling.
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  LOCK,     XXXXXXX, KC_LCTL, KC_LALT, KC_ESC,  SPC_GUI, ENT_GUI, RECT,    KC_LBRC, KC_RBRC, KC_MINS, KC_EQL \
),

/* ARROWS (blue underglow) - Cursor movement, media keys, and clipboard shortcuts
 * .-----------------------------------------.     .-----------------------------------------.
 * |      |      |      |      |      |      |     | Mute | Vol- | Vol+ |   -  |   =  |  BS  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  Tab |      |      |      |      |      |     |      | PvWd |  Up  | NxWd |      | DelR |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  BS  |      |      |      |(Held)|      |     | LSrt | Left | Down | Right| LEnd | Kill |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft|      |      |      |      |      |     |   =  |  Cut | Copy | Paste|      |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      | LCtrl| LAlt |  Esc |  Spc |     |  Ent | RECT |GUI-[ |GUI-] | RGB T|Reset |
 * `-----------------------------------------'     '-----------------------------------------'
 */
[_ARROWS] = LAYOUT( \
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_MINS, KC_EQL,  _______, \
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, PRV_WD,  KC_UP,   NXT_WD,  XXXXXXX, DEL_RT, \
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, LN_SRT,  KC_LEFT, KC_DOWN, KC_RGHT, LN_END,  KILL_LN, \
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  CUT,     COPY,    PASTE,   XXXXXXX, _______, \
  XXXXXXX,  XXXXXXX, _______, _______, _______, _______, _______, _______, GUI_BL,  GUI_BR,  RGB_TOG, RESET \
),

/* NAV (red underglow) - Navigation shortcuts and media keys
 * .-----------------------------------------.     .-----------------------------------------.
<<<<<<< HEAD
 * |  Esc |   B- |   B+ | Prev | Play | Next |     | Mute | Vol- | Vol+ |   -  |   =  |  BS  |
>>>>>>> Initial commit of my Nyquist keymap, based on my current Ergodox layout: https://configure.ergodox-ez.com/ergodox-ez/layouts/qn5G5/latest/0
=======
 * |  Esc |   B- |   B+ | Prev | Play | Next |     |      |      |      |      |      |  BS  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  Tab |      | Home | WhDn | End  | PgUp |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  BS  |      | WhRt | WhUp | WhLf | PgDn |     |      |(Held)|      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft|      |      |      |      |   -  |     |      |      |      |      |      |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Reset|      | LCtrl| LAlt |  Esc |  Spc |     |  Ent | RECT |      |      |      |      |
 * `-----------------------------------------'     '-----------------------------------------'
 */
[_NAV] = LAYOUT( \
  KC_ESC,   KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______,  XXXXXXX, KC_HOME, KC_WH_D, KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______,  XXXXXXX, KC_WH_R, KC_WH_U, KC_WH_L, KC_PGDN, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  RESET,    XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
),

/* RECT (lavender underglow) - Window management shortcuts for Rectangle
 * .-----------------------------------------.     .-----------------------------------------.
<<<<<<< HEAD
 * |      |      |      |      |      |      |     |      |      |      |      |      |  BS  |
>>>>>>> Adjusted the keys for triggering the layers, and added another layer for scrolling.
=======
 * |      | Hue+ | Sat+ | Val+ | Plain| RGB T|     |      |      |      |      |      |  BS  |
>>>>>>> Added RGB keycodes.
=======
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  Tab |      | UpLf | UpHf | UpRt |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  BS  | Disp-| LfHf | Full | RtHf |Disp+ |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft|      | LwLf | LwHf | LwRt |      |     |      |      |      |      |      |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
 * | Reset|      | LCtrl| LAlt |  Esc |  Spc |     |  Ent |(Held)|      |      |      |      |
 * `-----------------------------------------'     '-----------------------------------------'
 */
<<<<<<< HEAD
[_RECT] = LAYOUT( \
  XXXXXXX,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_P, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
<<<<<<< HEAD
  _______,  XXXXXXX, UP_LEFT, UP_HALF, UP_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______,  PRV_DIS, LF_HALF, FULLSCR, RT_HALF, NXT_DIS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
=======
 * | Reset|      | LCtrl| LAlt |  LWR |  Spc |     |  Ent |  RSE |      |      |      |      |
=======
 * | Reset|      | LCtrl| LAlt |  Esc |  Spc |     |  Ent |(Held)|      |      |      |      |
>>>>>>> Adjusted the keys for triggering the layers, and added another layer for scrolling.
 * `-----------------------------------------'     '-----------------------------------------'
 */
[_RECT] = LAYOUT( \
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
=======
>>>>>>> Added RGB keycodes.
  _______,  XXXXXXX, UP_LEFT, UP_HALF, UP_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
<<<<<<< HEAD
  _______,  PRV_DIS, LW_HALF, FULLSCR, RT_HALF, NXT_DIS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
>>>>>>> Initial commit of my Nyquist keymap, based on my current Ergodox layout: https://configure.ergodox-ez.com/ergodox-ez/layouts/qn5G5/latest/0
=======
  _______,  PRV_DIS, LF_HALF, FULLSCR, RT_HALF, NXT_DIS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
>>>>>>> Fix a typo.
  _______,  XXXXXXX, LW_LEFT, LW_HALF, LW_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  RESET,    XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
=======
=======
 * | Reset|      | LCtrl| LAlt |  Esc |  Spc |     |  Ent |(Held)|      |      |      |      |
 * `-----------------------------------------'     '-----------------------------------------'
 */
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
[_RECT] = LAYOUT(
  XXXXXXX,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_P, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______,  XXXXXXX, UP_LEFT, UP_HALF, UP_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,  PRV_DIS, LF_HALF, FULLSCR, RT_HALF, NXT_DIS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,  XXXXXXX, LW_LEFT, LW_HALF, LW_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  RESET,    XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
<<<<<<< HEAD
>>>>>>> Remove unnecessary trailing backslashes in the LAYOUT blocks,
)

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> Added support for lighting layers.
=======
)

>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
};

// Lighting layers
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
    {0, 12, 33, 255, 255} // #ffc700: 47, 100, 100
);
const rgblight_segment_t PROGMEM arrow_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, 140, 255, 232} // #00a3e9: 198, 100, 91
);
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, 0, 184, 237} // #ee4343: 0, 72, 93
);
const rgblight_segment_t PROGMEM rect_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, 168, 120, 255} // #878eff: 237, 47, 100
<<<<<<< HEAD
=======
    {0, 12, HSV_GOLD}
=======
    {0, 12, 33, 255, 255} // #ffc700: 47, 100, 100
>>>>>>> Tweak the colors for the lighting layers.
);
const rgblight_segment_t PROGMEM arrow_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, 140, 255, 232} // #00a3e9: 198, 100, 91
);
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, 0, 184, 237} // #ee4343: 0, 72, 93
);
const rgblight_segment_t PROGMEM rect_layer[] = RGBLIGHT_LAYER_SEGMENTS(
<<<<<<< HEAD
    {0, 12, HSV_PURPLE}
>>>>>>> Added support for lighting layers.
=======
    {0, 12, 168, 120, 255} // #878eff: 237, 47, 100
>>>>>>> Tweak the colors for the lighting layers.
=======
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    arrow_layer,
    nav_layer,
    rect_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_set_layer_state(_QWERTY, 1);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(_QWERTY, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(_ARROWS, layer_state_cmp(state, _ARROWS));
    rgblight_set_layer_state(_NAV, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(_RECT, layer_state_cmp(state, _RECT));
    return state;
}
<<<<<<< HEAD
<<<<<<< HEAD
=======
};
>>>>>>> Initial commit of my Nyquist keymap, based on my current Ergodox layout: https://configure.ergodox-ez.com/ergodox-ez/layouts/qn5G5/latest/0
=======
>>>>>>> Added support for lighting layers.
=======
>>>>>>> 98b9290203ad005ca732a6c689325c9bafa2a830
