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

#define _QWERTY 0
#define _ARROWS 1
#define _NAV 2
#define _NUMPAD 3
#define _RECT 4
#define _GAMING 5

// Layers
#define ARW_F LT(_ARROWS, KC_F)           // Momentarily activate layer 1 when held, and F when tapped
#define ARW_TOG TG(_ARROWS)               // Toggles layer 1 on and off
#define NAV_J LT(_NAV, KC_J)              // Momentarily activate layer 2 when held, and J when tapped
#define NUM_G LT(_NUMPAD, KC_G)           // Momentarily activate layer 3 when held, and G when tapped
#define NUM_V LT(_NUMPAD, KC_V)           // Momentarily activate layer 3 when held, and V when tapped
#define RECT_H LT(_RECT, KC_H)            // Momentarily activate layer 4 when held, and H when tapped
#define RECT_M LT(_RECT, KC_M)            // Momentarily activate layer 4 when held, and M when tapped
#define GAM_TOG TG(_GAMING)               // Toggles layer 5 on and off

// Mod-Taps
#define CMD_SPC LGUI_T(KC_SPC)            // ⌘ when held, Space when tapped
#define CMD_ENT RGUI_T(KC_ENT)            // ⌘ when held, Enter when tapped
#define SHIFT_D LSFT_T(KC_D)              // ⇧ when held, D when tapped
#define SHIFT_K RSFT_T(KC_K)              // ⇧ when held, K when tapped
#define ALT_S LALT_T(KC_S)                // ⌥ when held, S when tapped
#define ALT_L RALT_T(KC_L)                // ⌥ when held, L when tapped
#define CTL_A LCTL_T(KC_A)                // ^ when held, A when tapped
#define CTL_QT RCTL_T(KC_QUOT)            // ^ when held, ' when tapped

// Shortcuts
#define MIC_TOG LSFT(LGUI(KC_A))          // ⇧⌘A: Mute or un-mute the mic in Zoom
#define SCR_LCK LCTL(LGUI(KC_Q))          // ⌘^Q: Lock screen
#define CAM_TOG LCTL(LSFT(LGUI(KC_V)))    // ^⇧⌘V: Turn the camera off or on in Zoom
#define ZOM_END LCTL(LSFT(LGUI(LALT(KC_GRV))))    // ^⇧⌘⌥`: Leave Zoom meeting
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

// GSheets shortcuts (https://support.google.com/docs/answer/181110). Not currently used, but I plan to add a layer for these.
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

// RGB
#define BRIGHTNESS 80

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: QWERTY layer (yellow underglow)
 *
 *      ,------.------.------.------.------.                                                                   ,------.------.------.------.------.
 *      |   1  |   2  |   3  |   4  |   5  |                                                                   |   6  |   7  |   8  |   9  |   0  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   Q  |   W  |   E  |   R  |   T  |                                                                   |   Y  |   U  |   I  |   O  |   P  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      | A(^) | S(⌥) | D(⇧) | F(1) |   G  |                                                                   |   H  | J(2) | K(⇧) | L(⌥) | '(^) |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   Z  |   X  |   C  | V(3) |   B  |                                                                   |   N  | M(4) |   ,  |   .  |   /  |
 *      `------'------'------'------'------',------.                                                   ,------.`------'------'------'------'------'
 *                                   ,------|      |------. ,----------. ,-------. ,----------. ,------|      |------.
 *                                   |      |  Spc |      | |Mic Toggle| |ScrnLck| | Zoom End | |      |  Ent |      |
 *                                   |  Esc |  (⌘) |  Del | `----------' `-------' `----------' |  BS  |  (⌘) |  Tab |
 *                                   |      |      |      |                                     |      |      |      |
 *                                   `------'------'------'                                     `------'------'------'
 */
[_QWERTY] = LAYOUT(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  CTL_A,   ALT_S,   SHIFT_D, ARW_F,   KC_G,                                                                   KC_H,    NAV_J,   SHIFT_K, ALT_L,   CTL_QT,
  KC_Z,    KC_X,    KC_C,    NUM_V,   KC_B,                                                                   KC_N,    RECT_M,  KC_COMM, KC_DOT,  KC_SLSH,
                                      KC_ESC,  CMD_SPC, KC_DEL,  MIC_TOG, SCR_LCK, ZOM_END, KC_BSPC, CMD_ENT, KC_TAB
),

/* Keymap 1: Arrows layer (blue underglow) - Cursor movement, media keys, numpad, and clipboard shortcuts
 *
 *      ,------.------.------.------.------.                                                                   ,------.------.------.------.------.
 *      |      |      |      |      |      |                                                                   | Mute | Vol- | Vol+ |      |      |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |      |      |      |      |      |                                                                   |   ]  | PvWd |  Up  | NxWd |   \  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   ^  |   ⌥  |   ⇧  |(held)|      |                                                                   |   =  | Left | Down | Right|   ;  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |      |      |      |      |      |                                                                   | Undo |  Cut | Copy | Paste|      |
 *      `------'------'------'------'------',------.                                                   ,------.`------'------'------'------'------'
 *                                   ,------|      |------. ,----------. ,-------. ,----------. ,------|      |------.
 *                                   |      |  Spc |      | |Mic Toggle| | Reset | | Zoom End | |      |  Ent |      |
 *                                   |  Esc |  (⌘) |  Del | `----------' `-------' `----------' |  BS  |  (⌘) |  Tab |
 *                                   |      |      |      |                                     |      |      |      |
 *                                   `------'------'------'                                     `------'------'------'
 */
[_ARROWS] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                                KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                                KC_RBRC, PRV_WD,  KC_UP,   NXT_WD,  KC_BSLS,
  KC_LCTL, KC_LALT, KC_LSFT, _______, XXXXXXX,                                                                KC_EQL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                                UNDO,    CUT,     COPY,    PASTE,   XXXXXXX,
                                      _______, _______, _______, _______, RESET,   _______, _______, _______, _______
),

/* Keymap 2: Nav layer (red underglow) - Navigation shortcuts and media keys
 *
 *      ,------.------.------.------.------.                                                                   ,------.------.------.------.------.
 *      | Bri- | Bri+ | Prev | Play | Next |                                                                   |      |      |      |      |      |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   `  | Home | WhDn | End  |   [  |                                                                   |      |      |      |      |      |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      | Vol+ | WhRt | WhUp | WhLf |   -  |                                                                   |      |(held)|   ⇧  |   ⌥  |   ^  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      | Vol- |      |  ⌘[  |  ⌘]  |      |                                                                   |      |      |      |      |      |
 *      `------'------'------'------'------',------.                                                   ,------.`------'------'------'------'------'
 *                                   ,------|      |------. ,----------. ,-------. ,----------. ,------|      |------.
 *                                   |      |  Spc |      | |Cam Toggle| | Reset | | Zoom End | |      |  Ent |      |
 *                                   |  Esc |  (⌘) |  Del | `----------' `-------' `----------' |  BS  |  (⌘) |  Tab |
 *                                   |      |      |      |                                     |      |      |      |
 *                                   `------'------'------'                                     `------'------'------'
 */
[_NAV] = LAYOUT(
  KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT,                                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_GRV,  KC_HOME, KC_WH_D, KC_END,  KC_LBRC,                                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_VOLU, KC_WH_R, KC_WH_U, KC_WH_L, KC_MINS,                                                                XXXXXXX, _______, KC_RSFT, KC_RALT, KC_RCTL,
  KC_VOLD, XXXXXXX, GUI_BL,  GUI_BR,  XXXXXXX,                                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      _______, _______, _______, CAM_TOG, RESET,   _______, _______, _______, _______
),

/* Keymap 3: Numpad (orange underglow)
 *
 *      ,------.------.------.------.------.                                                                   ,------.------.------.------.------.
 *      |      |      |      |      |      |                                                                   |      |      |      |      |      |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |      |      |      |      |      |                                                                   |   *  |   7  |   8  |   9  |   /  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   ^  |   ⌥  |   ⇧  |      |      |                                                                   |   =  |   4  |   5  |   6  |   0  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |      |      |      |(held)|      |                                                                   |   -  |   1  |   2  |   3  |   .  |
 *      `------'------'------'------'------',------.                                                   ,------.`------'------'------'------'------'
 *                                   ,------|      |------. ,----------. ,-------. ,----------. ,------|      |------.
 *                                   |      |  Spc |      | |Mic Toggle| | Reset | | Zoom End | |      |  Ent |      |
 *                                   |  Esc |  (⌘) |  Del | `----------' `-------' `----------' |  BS  |  (⌘) |  Tab |
 *                                   |      |      |      |                                     |      |      |      |
 *                                   `------'------'------'                                     `------'------'------'
 */
[_NUMPAD] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                                KC_PAST, KC_7,    KC_8,    KC_9,    KC_PSLS,
  KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX, XXXXXXX,                                                                KC_EQL,  KC_4,    KC_5,    KC_6,    KC_0,
  XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,                                                                KC_PMNS, KC_1,    KC_2,    KC_3,    KC_PDOT,
                                      _______, _______, _______, _______, RESET,   _______, _______, _______, _______
),

/* Keymap 4: Rectangle layer (lavender underglow) - Window management shortcuts for Rectangle
 *
 *      ,------.------.------.------.------.                                                                   ,------.------.------.------.------.
 *      |      |      |      |      |      |                                                                   |      |      |      |      |      |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |      | UpLf | UpHf | UpRt |      |                                                                   |      |      |      |      |      |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      | Disp-| LfHf | Full | RtHf | Disp+|                                                                   |      |      |      |      |      |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |      | LwLf | LwHf | LwRt |      |                                                                   |      |(held)|      |      |      |
 *      `------'------'------'------'------',------.                                                   ,------.`------'------'------'------'------'
 *                                   ,------|      |------. ,----------. ,-------. ,----------. ,------|      |------.
 *                                   |      |  Spc |      | |Mic Toggle| | TG(5) | | Zoom End | |      |  Ent |      |
 *                                   |  Esc |  (⌘) |  Del | `----------' `-------' `----------' |  BS  |  (⌘) |  Tab |
 *                                   |      |      |      |                                     |      |      |      |
 *                                   `------'------'------'                                     `------'------'------'
 */
[_RECT] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, UP_LEFT, UP_HALF, UP_RGHT, XXXXXXX,                                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  PRV_DIS, LF_HALF, FULLSCR, RT_HALF, NXT_DIS,                                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, LW_LEFT, LW_HALF, LW_RGHT, XXXXXXX,                                                                XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,
                                      _______, _______, _______, _______, GAM_TOG, _______, _______, _______, _______
),

/* Keymap 5: Gaming layer (green underglow)
 *
 *      ,------.------.------.------.------.                                                                   ,------.------.------.------.------.
 *      |   1  |   2  |   3  |   4  |   5  |                                                                   |   6  |   7  |   8  |   9  |   0  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   Q  |   W  |   E  |   R  |   T  |                                                                   |   Y  |   U  |   I  |   O  |   P  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   A  |   S  |   D  |   F  |   G  |                                                                   | H(4) | J(2) | K(⇧) | L(⌥) | '(^) |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   Z  |   X  |   C  |   V  |   B  |                                                                   |   N  | M(4) |   ,  |   .  |   /  |
 *      `------'------'------'------'------',------.                                                   ,------.`------'------'------'------'------'
 *                                   ,------|      |------. ,----------. ,-------. ,----------. ,------|      |------.
 *                                   |      |  Spc |      | |Mic Toggle| | TG(5) | | Zoom End | |      |  Ent |      |
 *                                   |  Esc |      |  Del | `----------' `-------' `----------' |  BS  |  (⌘) |  Tab |
 *                                   |      |      |      |                                     |      |      |      |
 *                                   `------'------'------'                                     `------'------'------'
 */
[_GAMING] = LAYOUT(
  _______, _______, _______, _______, _______,                                                                _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                                                _______, _______, _______, _______, _______,
  KC_A,    KC_S,    KC_D,    KC_F,    _______,                                                                _______, _______, _______, _______, _______,
  _______, _______, _______, KC_V,    _______,                                                                _______, _______, _______, _______, _______,
                                      _______, KC_SPC,  _______, _______, GAM_TOG, _______, _______, _______, _______
)

};

// Lighting layer
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 33, 255, BRIGHTNESS}
);
const rgblight_segment_t PROGMEM arrow_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 140, 255, BRIGHTNESS}
);
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 220, 255, BRIGHTNESS} // 0, 153
);
const rgblight_segment_t PROGMEM numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 14, 255, BRIGHTNESS}
);
const rgblight_segment_t PROGMEM rect_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 183, 217, BRIGHTNESS}
);
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 85, 255, BRIGHTNESS}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    arrow_layer,
    nav_layer,
    numpad_layer,
    rect_layer,
    gaming_layer
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
    rgblight_set_layer_state(_NUMPAD, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(_RECT, layer_state_cmp(state, _RECT));
    rgblight_set_layer_state(_GAMING, layer_state_cmp(state, _GAMING));
    return state;
}

// Combos
enum combos {
  ESC_TAB_CAPSLOCK
};

const uint16_t PROGMEM esc_tab_combo[] = {KC_ESC, KC_TAB, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ESC_TAB_CAPSLOCK] = COMBO(esc_tab_combo, KC_CAPSLOCK)
};
