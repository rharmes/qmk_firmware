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

// Layout: http://www.keyboard-layout-editor.com/#/gists/aaa64d553c73dd6a8e15c7e91637d76c
// Finger assignments: http://www.keyboard-layout-editor.com/#/gists/26b92acc628d7178145297d07cd5025a

#define _QWERTY 0
#define _ARROWS 1
#define _NAV 2
#define _RECT 3
#define _GAMING 4

// Layers
#define ARW_F LT(_ARROWS, KC_F)           // Momentarily activate layer 1 when held, and F when tapped
#define ARW_TOG TG(_ARROWS)               // Toggles layer 1 on and off
#define NAV_J LT(_NAV, KC_J)              // Momentarily activate layer 2 when held, and J when tapped
#define RECT_H LT(_RECT, KC_BSPC)         // Momentarily activate layer 3 when held, and H when tapped
#define GAM_TOG TG(_GAMING)               // Toggles layer 4 on and off

// Mod-Taps
#define CMD_SPC LGUI_T(KC_SPC)            // ⌘ when held, Sapce when tapped
#define CMD_ENT RGUI_T(KC_ENT)            // ⌘ when held, Enter when tapped
#define SHIFT_D LSFT_T(KC_D)              // ⇧ when held, D when tapped
#define SHIFT_K RSFT_T(KC_K)              // ⇧ when held, K when tapped
#define ALT_S LALT_T(KC_S)                // ⌥ when held, S when tapped
#define ALT_L RALT_T(KC_L)                // ⌥ when held, L when tapped
#define CTL_A LCTL_T(KC_A)                // ^ when held, A when tapped
#define CTL_CLN RCTL_T(KC_SCLN)           // ^ when held, ; when tapped

// Shortcuts
#define MIC_TOG LSFT(LGUI(KC_A))          // ⇧⌘A: Mute or un-mute the mic in Zoom
#define LOCK LCTL(LGUI(KC_Q))             // ⌘^Q: Lock screen
#define CAM_TOG LSFT(LGUI(KC_V))          // ⇧⌘V: Turn the camera off or on in Zoom
#define CUT LGUI(KC_X)                    // ⌘X: Cut
#define COPY LGUI(KC_C)                   // ⌘C: Copy
#define PASTE LGUI(KC_V)                  // ⌘V: Paste
#define UNDO LGUI(KC_Z)                   // ⌘Z: Undo
#define PRV_WD RALT(KC_LEFT)              // ⌥←: Move to the beginning of the previous word
#define NXT_WD RALT(KC_RGHT)              // ⌥→: Move to the end of the next word
#define LN_SRT RCTL(KC_A)                 // ^A: Move to the beginning of the line or paragraph
#define LN_END RCTL(KC_E)                 // ^E: Move to the end of a line or paragraph
#define DEL_RT RCTL(KC_D)                 // ^D: Delete the character to the right of the insertion point
#define KILL_LN RCTL(KC_K)                // ^K: Kill line
#define GUI_BL RGUI(KC_LBRC)              // ⌘[: Previous Channel in Slack
#define GUI_BR RGUI(KC_RBRC)              // ⌘]: Next Channel in Slack

// GSheets shortcuts (https://support.google.com/docs/answer/181110)
#define PST_VAL LSFT(LGUI(KC_V))          // ⇧⌘V: Paste values only
#define PST_STY LALT(LGUI(KC_V))          // ⌘⌥V: Paste styles only
#define SEL_ROW LSFT(KC_SPC)              // ⇧Space: Select row
#define SEL_COL LCTL(KC_SPC)              // ^Space: Select column
#define DEL_R_C LALT(LGUI(KC_MINS))       // ⌘⌥-: Deleted selected row or column
#define INS_R_C LALT(LGUI(KC_EQL))        // ⌘⌥=: Insert row above selected row, or insert column to the left of selected column
#define ROW_SRT KC_HOME                   // Home: Move to start of row
#define ROW_END KC_END                    // End: Move to end of row
#define SHT_TOP LGUI(KC_HOME)             // ⌘Home: Move to beginning of sheet
#define SHT_BOT LGUI(KC_END)              // ⌘End: Move to end of sheet
#define NXT_SHT LALT(KC_DOWN)             // ⌥↓: Move to next sheet 
#define PRV_SHT LALT(KC_UP)               // ⌥↑: Move to previous sheet 
#define FILE_M LCTL(LALT(KC_F))           // ^⌥F: Open File menu
#define BRD_TOP LALT(LSFT(KC_1))          // ⇧⌥1: Apply top border
#define BRD_BOT LALT(LSFT(KC_3))          // ⇧⌥3: Apply bottom border
#define BRD_LFT LALT(LSFT(KC_4))          // ⇧⌥4: Apply left border
#define BRD_RGT LALT(LSFT(KC_2))          // ⇧⌥2: Apply right border
#define BRD_OUT LALT(LSFT(KC_7))          // ⇧⌥7: Apply outer border
#define REM_BRD LALT(LSFT(KC_6))          // ⇧⌥6: Remove borders
#define ALN_LFT LGUI(LSFT(KC_L))          // ⌘⇧L: Align left
#define ALN_CEN LGUI(LSFT(KC_E))          // ⌘⇧E: Align center
#define ALN_RGT LGUI(LSFT(KC_R))          // ⌘⇧R: Align right

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

/* Keymap 0: QWERTY layer (yellow underglow)    
 *                                              ,-------------. ,--------------------. ,--------------------.
 *                                              | Bri- | Bri+ | | Prev | Play | Next | | Mute | Vol- | Vol+ |
 *     ,---------------------------------------.`-------------' `--------------------' `--------------------',----------------------------------------.
 *     | `  |   1  |   2  |   3  |   4  |   5  |           ,------.  ,---------------------------.           |   6  |   7  |   8  |   9  |   0  |   \ |
 *  ,--+----+------+------+------+------+------|           | DelR |  | TG(1)| ShTop|ShBotm| File |           |------+------+------+------+------+-----+-.
 *  |  Tab  |   Q  |   W  |   E  |   R  |   T  |------.    |------|  |------+------+------+------|    ,------|   Y  |   U  |   I  |   O  |   P  |   '   |
 *  |-------+------+------+------+------+------|   [  |    | InsR |  | RSrt |  Up  | REnd | NxSh |    |  ]   |------+------+------+------+------+-------|
 *  |   BS  | A(^) | S(⌥) | D(⇧) | F(1) |   G  |------|    |------|  |------+------+------+------|    |------| H(3) | J(2) | K(⇧) | L(⌥) | ;(^) |  BS   |
 * ,--------+------+------+------+------+------|   -  |    | SelR |  | Left | Down | Right| PvSh |    |  =   |------+------+------+------+------+--------.
 * |    ⇧   |   Z  |   X  |   C  |   V  |   B  |------'    |------|  |------+------+------+------|    `------|   N  |   M  |   ,  |   .  |   /  |   ⇧    |
 * `--------+------+------+------+------+------'           | SelC |  |  Cut | Copy | Paste|      |           `------+------+------+------+------+--------'
 *                 |   ^  |   ⌥  |  Esc | ,-------------.  |------|  |------+------+------+  Ent |  ,-------------. |  Tab |   ⌥  |   ^  |
 *                 `--------------------' |  BS  |      |  | BS(3)|  | Paste Values|PstSty|      |  |      |  BS  | `--------------------'
 *                                        |      |  Spc |  '------'  `---------------------------'  |  Ent |      |  
 *                                        `------|  (⌘) | ,----------------. ,-------. ,----------. |  (⌘) |------'
 *                                               |      | |   Mic Toggle   | |ScrnLck| |Cam Toggle| |      | 
 *                                               `------' `----------------' `-------' `----------' `------'
 */
[_QWERTY] = LAYOUT(
                                                                 KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,                                                               
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      DEL_R_C,          ARW_TOG, SHT_TOP, SHT_BOT, FILE_M,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          INS_R_C,          ROW_SRT, KC_UP,   ROW_END, NXT_SHT,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  KC_BSPC, CTL_A,   ALT_S,   SHIFT_D, ARW_F,   KC_G,    KC_MINS,          SEL_ROW,          KC_LEFT, KC_DOWN, KC_RGHT, PRV_SHT,          KC_EQL,  RECT_H,  NAV_J,   SHIFT_K, ALT_L,   CTL_CLN, KC_BSPC,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      SEL_COL,          CUT,     COPY,    PASTE,   KC_PENT,                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_LCTL, KC_LALT, KC_ESC,                             RECT_BS,          PST_VAL,          PST_STY,                                     KC_TAB,  KC_RALT, KC_RCTL,                  
                                               KC_BSPC, CMD_SPC,          MIC_TOG,          LOCK,             CAM_TOG,                   CMD_ENT, KC_BSPC                                              
),

/* Keymap 1: Arrows layer (blue underglow) - Cursor movement, media keys, numpad, and clipboard shortcuts   
 *                                              ,-------------. ,--------------------. ,--------------------.
 *                                              | Bri- | Bri+ | | Prev | Play | Next | | Mute | Vol- | Vol+ |
 *     ,---------------------------------------.`-------------' `--------------------' `--------------------',----------------------------------------.
 *     | `  |      |      |      |      |      |           ,------.  ,---------------------------.           | Mute | Vol- | Vol+ |      |      | Kill|
 *  ,--+----+------+------+------+------+------|           | DelR |  | TG(1)|   ÷  |   ×  |   =  |           |------+------+------+------+------+-----+-.
 *  |  Tab  |      |      |      |      |      |------.    |------|  |------+------+------+------|    ,------|      | PvWd |  Up  | NxWd |      | DelR  |
 *  |-------+------+------+------+------+------|   [  |    | InsR |  |   7  |   8  |   9  |   -  |    |  ]   |------+------+------+------+------+-------|
 *  |   BS  |   ^  |   ⌥  |   ⇧  |(held)|      |------|    |------|  |------+------+------+------|    |------| LSrt | Left | Down | Right| LEnd |  BS   |
 * ,--------+------+------+------+------+------|   -  |    | SelR |  |   4  |   5  |   6  |   +  |    |  =   |------+------+------+------+------+--------.
 * |    ⇧   |      |      |      |      |      |------'    |------|  |------+------+------+------|    `------|   =  |  Cut | Copy | Paste| Undo |   ⇧    |
 * `--------+------+------+------+------+------'           | SelC |  |   1  |   2  |   3  |      |           `------+------+------+------+------+--------'
 *                 |   ^  |   ⌥  |  Esc | ,-------------.  |------|  |------+------+------+  Ent |  ,-------------. |  Tab |  ⌘[  |  ⌘]  |
 *                 `--------------------' |  BS  |      |  | BS(3)|  |      0      |   .  |      |  |      |  BS  | `--------------------'
 *                                        |      |  Spc |  '------'  `---------------------------'  |  Ent |      |  
 *                                        `------|  (⌘) | ,----------------. ,-------. ,----------. |  (⌘) |------'
 *                                               |      | |   Mic Toggle   | | Reset | |Cam Toggle| |      | 
 *                                               `------' `----------------' `-------' `----------' `------'
 */
[_ARROWS] = LAYOUT(
                                                                 _______, _______, _______, _______, _______, _______, _______, _______,                                                               
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______,          _______, KC_PSLS, KC_PAST, KC_PEQL,                   KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KILL_LN,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______,          KC_P7,   KC_P8,   KC_P9,   KC_PMNS,          _______, XXXXXXX, PRV_WD,  KC_UP,   NXT_WD,  XXXXXXX, DEL_RT, 
  _______, KC_LCTL, KC_LALT, KC_LSFT, _______, XXXXXXX, _______,          _______,          KC_P4,   KC_P5,   KC_P6,   KC_PPLS,          _______, LN_SRT,  KC_LEFT, KC_DOWN, KC_RGHT, LN_END,  _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______,          KC_P1,   KC_P2,   KC_P3,   KC_PENT,                   KC_EQL,  CUT,     COPY,    PASTE,   UNDO,    _______,
                    _______, _______, _______,                            _______,          KC_P0,            KC_PDOT,                                     _______, GUI_BL,  GUI_BR,                   
                                               _______, _______,          _______,          RESET,            _______,                   _______, _______                                              
),

/* Keymap 2: Nav layer (red underglow) - Navigation shortcuts and media keys   
 *                                              ,-------------. ,--------------------. ,--------------------.
 *                                              | Bri- | Bri+ | | Prev | Play | Next | | Mute | Vol- | Vol+ |
 *     ,---------------------------------------.`-------------' `--------------------' `--------------------',----------------------------------------.
 *     | `  | Bri- | Bri+ | Prev | Play | Next |           ,------.  ,---------------------------.           |      |      |      |      |      |   \ |
 *  ,--+----+------+------+------+------+------|           | DelR |  | TG(1)| ShTop|ShBotm| File |           |------+------+------+------+------+-----+-.
 *  |  Tab  |      | Home | WhDn | End  | PgUp |------.    |------|  |------+------+------+------|    ,------|      |      |      |      |      |   '   |
 *  |-------+------+------+------+------+------|   [  |    | InsR |  | RSrt |  Up  | REnd | NxSh |    |  ]   |------+------+------+------+------+-------|
 *  |   BS  |      | WhRt | WhUp | WhLf | PgDn |------|    |------|  |------+------+------+------|    |------|      |(held)|   ⇧  |   ⌥  |   ^  |  BS   |
 * ,--------+------+------+------+------+------|   -  |    | SelR |  | Left | Down | Right| PvSh |    |  =   |------+------+------+------+------+--------.
 * |    ⇧   |      |      |      |      |   -  |------'    |------|  |------+------+------+------|    `------|      |      |      |      |      |   ⇧    |
 * `--------+------+------+------+------+------'           | SelC |  |  Cut | Copy | Paste|      |           `------+------+------+------+------+--------'
 *                 |   ^  |   ⌥  |  Esc | ,-------------.  |------|  |------+------+------+  Ent |  ,-------------. |  Tab |   ⌥  |   ^  |
 *                 `--------------------' |  BS  |      |  | BS(3)|  | Paste Values|PstSty|      |  |      |  BS  | `--------------------'
 *                                        |      |  Spc |  '------'  `---------------------------'  |  Ent |      |  
 *                                        `------|  (⌘) | ,----------------. ,-------. ,----------. |  (⌘) |------'
 *                                               |      | |   Mic Toggle   | | Reset | |Cam Toggle| |      | 
 *                                               `------' `----------------' `-------' `----------' `------'
 */
[_NAV] = LAYOUT(
                                                                 _______, _______, _______, _______, _______, _______, _______, _______,                                                               
  _______, KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT,                   _______,          _______, _______, _______, _______,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, KC_HOME, KC_WH_D, KC_END,  KC_PGUP, _______,          _______,          _______, _______, _______, _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, KC_WH_R, KC_WH_U, KC_WH_L, KC_PGDN, _______,          _______,          _______, _______, _______, _______,          _______, XXXXXXX, _______, KC_RSFT, KC_RALT, KC_RCTL, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS,                   _______,          _______, _______, _______, _______,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                    _______, _______, _______,                            _______,          _______,          _______,                                     _______, _______, _______,                  
                                               _______, _______,          _______,          RESET,            _______,                   _______, _______                                              
),

/* Keymap 3: Rectangle layer (lavender underglow) - Window management shortcuts for Rectangle and formating shortcuts for GSheet
 *                                              ,-------------. ,--------------------. ,--------------------.
 *                                              | Bri- | Bri+ | | Prev | Play | Next | | Mute | Vol- | Vol+ |
 *     ,---------------------------------------.`-------------' `--------------------' `--------------------',----------------------------------------.
 *     | `  |      |      |      |      |      |           ,------.  ,---------------------------.           |      |      |      |      |      |   \ |
 *  ,--+----+------+------+------+------+------|           | DelR |  | TG(1)|      |      |      |           |------+------+------+------+------+-----+-.
 *  |  Tab  |      | UpLf | UpHf | UpRt |      |------.    |------|  |------+------+------+------|    ,------|      |      |      |      |      |   '   |
 *  |-------+------+------+------+------+------|   [  |    | InsR |  | BdOut| BdTp | RemBD|      |    |  ]   |------+------+------+------+------+-------|
 *  |   BS  | Disp-| LfHf | Full | RtHf |Disp+ |------|    |------|  |------+------+------+------|    |------|(held)|      |      |      |      |  BS   |
 * ,--------+------+------+------+------+------|   -  |    | SelR |  | BdLf | BdBm | BdRt |      |    |  =   |------+------+------+------+------+--------.
 * |    ⇧   |      | LwLf | LwHf | LwRt |      |------'    |------|  |------+------+------+------|    `------|      |      |      |      |      |   ⇧    |
 * `--------+------+------+------+------+------'           | SelC |  | AlLf | AlCen| AlRt |      |           `------+------+------+------+------+--------'
 *                 |   ^  |   ⌥  |  Esc | ,-------------.  |------|  |------+------+------+  Ent |  ,-------------. |  Tab |   ⌥  |   ^  |
 *                 `--------------------' |  BS  |      |  |(held)|  |             |      |      |  |      |  BS  | `--------------------'
 *                                        |      |  Spc |  '------'  `---------------------------'  |  Ent |      |  
 *                                        `------|  (⌘) | ,----------------. ,-------. ,----------. |  (⌘) |------'
 *                                               |      | |   Mic Toggle   | | TG(4) | |Cam Toggle| |      | 
 *                                               `------' `----------------' `-------' `----------' `------'
 */
[_RECT] = LAYOUT(
                                                                 _______, _______, _______, _______, _______, _______, _______, _______,                                                               
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______,          _______, _______, _______, _______,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, UP_LEFT, UP_HALF, UP_RGHT, XXXXXXX, _______,          _______,          BRD_OUT, BRD_TOP, REM_BRD, _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, PRV_DIS, LF_HALF, FULLSCR, RT_HALF, NXT_DIS, _______,          _______,          BRD_LFT, BRD_BOT, BRD_RGT, _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, LW_LEFT, LW_HALF, LW_RGHT, XXXXXXX,                   _______,          ALN_LFT, ALN_CEN, ALN_RGT, _______,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                    _______, _______, _______,                            _______,          _______,          _______,                                     _______, _______, _______,                  
                                               _______, _______,          _______,          GAM_TOG,          _______,                   _______, _______                                              
),

/* Keymap 4: Gaming layer (green underglow)    
 *                                              ,-------------. ,--------------------. ,--------------------.
 *                                              | Bri- | Bri+ | | Prev | Play | Next | | Mute | Vol- | Vol+ |
 *     ,---------------------------------------.`-------------' `--------------------' `--------------------',----------------------------------------.
 *     | `  |   1  |   2  |   3  |   4  |   5  |           ,------.  ,---------------------------.           |   6  |   7  |   8  |   9  |   0  |   \ |
 *  ,--+----+------+------+------+------+------|           | DelR |  | TG(1)| ShTop|ShBotm| File |           |------+------+------+------+------+-----+-.
 *  |  Tab  |   Q  |   W  |   E  |   R  |   T  |------.    |------|  |------+------+------+------|    ,------|   Y  |   U  |   I  |   O  |   P  |   '   |
 *  |-------+------+------+------+------+------|   6  |    | InsR |  | RSrt |  Up  | REnd | NxSh |    |  ]   |------+------+------+------+------+-------|
 *  |   BS  |   A  |   S  |   D  |   F  |   G  |------|    |------|  |------+------+------+------|    |------| H(3) | J(2) | K(⇧) | L(⌥) | ;(^) |  BS   |
 * ,--------+------+------+------+------+------|   -  |    | SelR |  | Left | Down | Right| PvSh |    |  =   |------+------+------+------+------+--------.
 * |    ⇧   |   Z  |   X  |   C  |   V  |   B  |------'    |------|  |------+------+------+------|    `------|   N  |   M  |   ,  |   .  |   /  |   ⇧    |
 * `--------+------+------+------+------+------'           | SelC |  |  Cut | Copy | Paste|      |           `------+------+------+------+------+--------'
 *                 |   ^  |   ⌥  |  Esc | ,-------------.  |------|  |------+------+------+  Ent |  ,-------------. |  Tab |   ⌥  |   ^  |
 *                 `--------------------' |  BS  |      |  | BS(3)|  | Paste Values|PstSty|      |  |      |  BS  | `--------------------'
 *                                        |      |  Spc |  '------'  `---------------------------'  |  Ent |      |  
 *                                        `------|      | ,----------------. ,-------. ,----------. |  (⌘) |------'
 *                                               |      | |   Mic Toggle   | | TG(4) | |Cam Toggle| |      | 
 *                                               `------' `----------------' `-------' `----------' `------'
 */
[_QWERTY] = LAYOUT(
                                                                 _______, _______, _______, _______, _______, _______, _______, _______,                                                               
  _______, _______, _______, _______, _______, _______,                   _______,          _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_6,             _______,          _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  _______, KC_A,    KC_S,    KC_D,    KC_F,    _______, _______,          _______,          _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______,          _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                    _______, _______, _______,                            _______,          _______,          _______,                                     _______, _______, _______,                  
                                               _______, KC_SPC,           _______,          GAM_TOG,          _______,                   _______, _______                                              
)

};
