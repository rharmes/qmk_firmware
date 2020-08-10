 #include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

// Layers and mods
#define SPC_GUI LGUI_T(KC_SPC)            // ⌘ when held, Sapce when tapped
#define ENT_GUI RGUI_T(KC_ENT)            // ⌘ when held, Enter when tapped
#define LWR_ESC LT(_LOWER, KC_ESC)        // Momentarily activate layer 1 when held, and Escape when tapped
#define RSE MO(_RAISE)                    // Momentarily activate layer 2

// Shortcuts
#define LOCK LCTL(LGUI(KC_Q))             // ⌘^Q: Lock screen
#define UNDO LGUI(KC_Z)                   // ⌘Z: Undo
#define CUT LGUI(KC_X)                    // ⌘X: Cut
#define COPY LGUI(KC_C)                   // ⌘C: Copy
#define PASTE LGUI(KC_V)                  // ⌘C: Paste
#define PRV_WD RALT(RSFT(KC_LEFT))        // ⇧⌥←: Select to the beginning of the previous word
#define NXT_WD RALT(RSFT(KC_RGHT))        // ⇧⌥→: Select to the end of the next word
#define LN_SRT RCTL(KC_A)                 // ^A: Move to the beginning of the line or paragraph
#define LN_END RCTL(KC_E)                 // ^E: Move to the end of a line or paragraph
#define DEL_RT RCTL(KC_D)                 // ^D: Delete the character to the right of the insertion point
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

/* QWERTY
 * .-----------------------------------------.     .-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |  BS  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  BS  |   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lock |      | LCtrl| LAlt |  LWR |  Spc |     |  Ent |  RSE |   [  |   ]  |   -  |   =  |
 * `-----------------------------------------'     '-----------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH, \
  KC_BSPC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  LOCK,     XXXXXXX, KC_LCTL, KC_LALT, LWR_ESC, SPC_GUI, ENT_GUI, RSE,     KC_LBRC, KC_RBRC, KC_MINS, KC_EQL \
),

/* LOWER - Cursor movement, media keys, and clipboard shortcuts
 * .-----------------------------------------.     .-----------------------------------------.
 * |  Esc |   B- |   B+ | Prev | Play | Next |     | Mute | Vol- | Vol+ |   -  |   =  |  BS  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  Tab |      |      | PgUp |      |      |     |      | PvWd |  Up  | NxWd |      | DelR |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  BS  |      |      | PgDn |      |      |     | LSrt | Left | Down | Right| LEnd |  "   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft| Undo |  Cut | Copy | Paste|      |     |      |      |      |      |      |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      | LCtrl| LAlt |  LWR |  Spc |     |  Ent |  RSE |GUI-[ |GUI-] |      |Reset |
 * `-----------------------------------------'     '-----------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_ESC,   KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_MINS, KC_EQL,  _______, \
  _______,  XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, PRV_WD,  KC_UP,   NXT_WD,  XXXXXXX, DEL_RT, \
  _______,  XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, LN_SRT,  KC_LEFT, KC_DOWN, KC_RGHT, LN_END,  _______, \
  _______,  UNDO,    CUT,     COPY,    PASTE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  XXXXXXX,  XXXXXXX, _______, _______, _______, _______, _______, _______, GUI_BL,  GUI_BR,  XXXXXXX, RESET \
),

/* RAISE - Window management shortcuts for Rectangle and media keys
 * .-----------------------------------------.     .-----------------------------------------.
 * |  Esc |   B- |   B+ | Prev | Play | Next |     | Mute | Vol- | Vol+ |   -  |   =  |  BS  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  Tab |      | UpLf | UpHf | UpRt |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  BS  | Disp-| LfHf | Full | RtHf |Disp+ |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Lshft|      | LwLf | LwHf | LwRt |      |     |      |      |      |      |      |Rshft |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Reset|      | LCtrl| LAlt |  LWR |  Spc |     |  Ent |  RSE |      |      |      |      |
 * `-----------------------------------------'     '-----------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_ESC,   KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_MINS, KC_EQL,  _______, \
  _______,  XXXXXXX, UP_LEFT, UP_HALF, UP_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______,  PRV_DIS, LW_HALF, FULLSCR, RT_HALF, NXT_DIS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______,  XXXXXXX, LW_LEFT, LW_HALF, LW_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  RESET,    XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
)

};