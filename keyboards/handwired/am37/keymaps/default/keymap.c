/* Copyright 2026 Ross Harmes <ross@rossharmes.net>
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
#define _SYM 2
#define _NUMPAD 3
#define _RECT 4

// Layers
#define ARW_F LT(_ARROWS, KC_F)           // Momentarily activate layer 1 when held, and F when tapped
#define SYM_J LT(_SYM, KC_J)              // Momentarily activate layer 2 when held, and J when tapped
#define NUM_V LT(_NUMPAD, KC_V)           // Momentarily activate layer 3 when held, and V when tapped
#define RECT_M LT(_RECT, KC_M)            // Momentarily activate layer 4 when held, and M when tapped

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
#define EMOJI LCTL(LGUI(KC_SPC))          // ^⌘Space: Open the emoji menu

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

// Shifted symbols
#define SFT_1 LSFT(KC_1)                  // !
#define SFT_2 LSFT(KC_2)                  // @
#define SFT_3 LSFT(KC_3)                  // #
#define SFT_4 LSFT(KC_4)                  // $
#define SFT_5 LSFT(KC_5)                  // %
#define SFT_6 LSFT(KC_6)                  // ^
#define SFT_7 LSFT(KC_7)                  // &
#define SFT_8 LSFT(KC_8)                  // *
#define SFT_9 LSFT(KC_9)                  // (
#define SFT_0 LSFT(KC_0)                  // )
#define OPT_8 LALT(KC_8)                  // •

// RGB
#define BRIGHTNESS 80

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: QWERTY layer (yellow underglow, both hands)
 *
 *      ,------.------.------.------.------.                                                                   ,------.------.------.------.------.
 *      |   Q  |   W  |   E  |   R  |   T  |                                                                   |   Y  |   U  |   I  |   O  |   P  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      | A(^) | S(⌥) | D(⇧) | F(1) |   G  |                                                                   |   H  | J(2) | K(⇧) | L(⌥) | '(^) |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   Z  |   X  |   C  | V(3) |   B  |                                                                   |   N  | M(4) |   ,  |   .  |   /  |
 *      `------'------'------'------'------'                                                                   `------'------'------'------'------'
 *                                          ,------.------. ,----------. ,-------. ,----------. ,------.------.
 *                                          |      |      | |Mic Toggle| |ScrnLck| | Zoom End | |      |      |
 *                                          |  Spc |  Del | `----------' `-------' `----------' |  BS  |  Ent |
 *                                          |  (⌘) |      |                                     |      |  (⌘) |
 *                                          `------'------'                                     `------'------'
 */
[_QWERTY] = LAYOUT(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  CTL_A,   ALT_S,   SHIFT_D, ARW_F,   KC_G,                                                                   KC_H,    SYM_J,   SHIFT_K, ALT_L,   CTL_QT,
  KC_Z,    KC_X,    KC_C,    NUM_V,   KC_B,                                                                   KC_N,    RECT_M,  KC_COMM, KC_DOT,  KC_SLSH,
                                               CMD_SPC, KC_DEL, MIC_TOG, SCR_LCK, ZOM_END, KC_BSPC, CMD_ENT
),

/* Keymap 1: Arrows layer (cyan underglow, right hand) - Cursor movement, clipboard shortcuts, and symbols
 *
 *      ,------.------.------.------.------.                                                                   ,------.------.------.------.------.
 *      |      |      |      |      |      |                                                                   |   ]  | PvWd |  Up  | NxWd |   \  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   ^  |   ⌥  |   ⇧  |(held)|      |                                                                   |   =  | Left | Down | Right|   ;  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |      |      |      |      |      |                                                                   | Emoji|  Cut | Copy | Paste|   •  |
 *      `------'------'------'------'------'                                                                   `------'------'------'------'------'
 *                                          ,------.------. ,----------. ,-------. ,----------. ,------.------.
 *                                          |      |      | |Mic Toggle| | Reset | | Zoom End | |      |      |
 *                                          |  Spc |  Del | `----------' `-------' `----------' |  BS  |  Ent |
 *                                          |  (⌘) |      |                                     |      |  (⌘) |
 *                                          `------'------'                                     `------'------'
 */
[_ARROWS] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                                KC_RBRC, PRV_WD,  KC_UP,   NXT_WD,  KC_BSLS,
  KC_LCTL, KC_LALT, KC_LSFT, _______, XXXXXXX,                                                                KC_EQL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                                EMOJI,   CUT,     COPY,    PASTE,   OPT_8,
                                               _______, _______, _______, QK_BOOT, _______, _______, _______
),

/* Keymap 2: Symbol layer (magenta underglow, left hand)
 *
 *      ,------.------.------.------.------.                                                                   ,------.------.------.------.------.
 *      |   `  |   %  |   *  |   &  |   [  |                                                                   |      |      |      |      |      |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   !  |   $  |   (  |   )  |   -  |                                                                   |      |(held)|   ⇧  |   ⌥  |   ^  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   ^  |   @  |  ⌘[  |  ⌘]  |   #  |                                                                   |      |      |      |      |      |
 *      `------'------'------'------'------'                                                                   `------'------'------'------'------'
 *                                          ,------.------. ,----------. ,-------. ,----------. ,------.------.
 *                                          |      |      | |Cam Toggle| | Reset | | Zoom End | |      |      |
 *                                          |  Tab |  Esc | `----------' `-------' `----------' |  BS  |  Ent |
 *                                          |      |      |                                     |      |  (⌘) |
 *                                          `------'------'                                     `------'------'
 */
[_SYM] = LAYOUT(
  KC_GRV,  SFT_5,   SFT_8,   SFT_7,   KC_LBRC,                                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  SFT_1,   SFT_4,   SFT_9,   SFT_0,   KC_MINS,                                                                XXXXXXX, _______, KC_RSFT, KC_RALT, KC_RCTL,
  SFT_6,   SFT_2,   GUI_BL,  GUI_BR,  SFT_3,                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                               KC_TAB,  KC_ESC,  CAM_TOG, QK_BOOT, _______, _______, _______
),

/* Keymap 3: Numpad (green underglow, right hand)
 *
 *      ,------.------.------.------.------.                                                                   ,------.------.------.------.------.
 *      |      |      |      |      |      |                                                                   |   *  |   7  |   8  |   9  |   /  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |   ^  |   ⌥  |   ⇧  |      |      |                                                                   |   +  |   4  |   5  |   6  |   0  |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |      |      |      |(held)|      |                                                                   |   -  |   1  |   2  |   3  |   .  |
 *      `------'------'------'------'------'                                                                   `------'------'------'------'------'
 *                                          ,------.------. ,----------. ,-------. ,----------. ,------.------.
 *                                          |      |      | |Mic Toggle| |ScrnLck| | Zoom End | |      |      |
 *                                          |  Spc |  Del | `----------' `-------' `----------' |  BS  |  Ent |
 *                                          |  (⌘) |      |                                     |      |  (⌘) |
 *                                          `------'------'                                     `------'------'
 */
[_NUMPAD] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                                KC_PAST, KC_7,    KC_8,    KC_9,    KC_PSLS,
  KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX, XXXXXXX,                                                                KC_PPLS, KC_4,    KC_5,    KC_6,    KC_0,
  XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,                                                                KC_PMNS, KC_1,    KC_2,    KC_3,    KC_PDOT,
                                               _______, _______, _______, _______, _______, _______, _______
),

/* Keymap 4: Rectangle layer (orange underglow, left hand) - Window management shortcuts for Rectangle
 *
 *      ,------.------.------.------.------.                                                                   ,------.------.------.------.------.
 *      |      | UpLf | UpHf | UpRt | WhDn |                                                                   |      |      |      |      |      |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      | Disp-| LfHf | Full | RtHf | Disp+|                                                                   |      |      |      |      |      |
 *      |------+------+------+------+------|                                                                   |------+------+------+------+------|
 *      |      | LwLf | LwHf | LwRt | WhUp |                                                                   |      |(held)|      |      |      |
 *      `------'------'------'------'------'                                                                   `------'------'------'------'------'
 *                                          ,------.------. ,----------. ,-------. ,----------. ,------.------.
 *                                          |      |      | |Mic Toggle| |ScrnLck| | Zoom End | |      |      |
 *                                          |  Spc |  Del | `----------' `-------' `----------' |  BS  |  Ent |
 *                                          |  (⌘) |      |                                     |      |  (⌘) |
 *                                          `------'------'                                     `------'------'
 */
[_RECT] = LAYOUT(
  XXXXXXX, UP_LEFT, UP_HALF, UP_RGHT, MS_WHLD,                                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  PRV_DIS, LF_HALF, FULLSCR, RT_HALF, NXT_DIS,                                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, LW_LEFT, LW_HALF, LW_RGHT, MS_WHLU,                                                                XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,
                                               _______, _______, _______, _______, _______, _______, _______
)

};

// Lighting layers
//
// Two LEDs, daisy-chained: index 0 sits under the left hand, index 1 under the
// right. Each layer lights the hand its keys are on -- which is the hand that
// isn't holding the layer -- and blacks the other one out. Black rather than no
// segment at all: an LED no segment covers keeps whatever the QWERTY layer
// painted underneath, since layers are written in ascending order.
#define LEFT_LED 0, 1
#define RIGHT_LED 1, 1
#define HSV_UNLIT 0, 0, 0

const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, 33, 255, BRIGHTNESS} // Yellow on both hands
);
const rgblight_segment_t PROGMEM arrow_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEFT_LED, HSV_UNLIT},
    {RIGHT_LED, 140, 255, BRIGHTNESS} // Cyan: arrows are on the right hand
);
const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEFT_LED, 220, 255, BRIGHTNESS}, // Magenta: symbols are on the left hand
    {RIGHT_LED, HSV_UNLIT}
);
const rgblight_segment_t PROGMEM numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEFT_LED, HSV_UNLIT},
    {RIGHT_LED, 85, 255, BRIGHTNESS} // Green: the numpad is on the right hand
);
const rgblight_segment_t PROGMEM rect_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEFT_LED, 14, 255, BRIGHTNESS}, // Orange: window controls are on the left hand
    {RIGHT_LED, HSV_UNLIT}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    arrow_layer,
    sym_layer,
    numpad_layer,
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
    rgblight_set_layer_state(_SYM, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(_NUMPAD, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(_RECT, layer_state_cmp(state, _RECT));
    return state;
}

// Turn the underglow off when locking the screen, and back on at the next key press
static bool rgb_asleep = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == SCR_LCK) {
        // Wait for the release so the lock shortcut isn't delayed by the LED update
        if (!record->event.pressed) {
            rgb_asleep = true;
            rgblight_disable_noeeprom();
        }
    } else if (rgb_asleep && record->event.pressed) {
        // Layer lights keep tracking the layer state while off, so this restores the right color
        rgb_asleep = false;
        rgblight_enable_noeeprom();
    }
    return true;
}

// Combos
enum combos {
  DEL_BSPC_CAPSLOCK
};

const uint16_t PROGMEM del_bspc_combo[] = {KC_DEL, KC_BSPC, COMBO_END};

combo_t key_combos[] = {
  [DEL_BSPC_CAPSLOCK] = COMBO(del_bspc_combo, KC_CAPS)
};
