#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0      // default layer
#define TEXTEDIT 1  // symbols
#define MDIA 2      // media keys
#define WASD 3      // layer without mod-tap keys on wasd

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Main layer
 * ,----------------------------------------------------.   ,--------------------------------------------------.
 * |Esc    |  1 |    2    |  3    |  4    |  5    |PGUP |   |Ins  |  6    |  7    |  8    |  9    |  0 |  -    |
 * |-------+----+---------+-------+-------+-------+-----|   |-----+-------+-------+-------+-------+----+-------|
 * |Tab    |  Q |    W    |  E    |  R    |  T    |PGDN |   |Pause|  Y    |  U    |  I    |  O    |  P |  =    |
 * |-------+----+---------+-------+-------+-------|     |   |     |-------+-------+-------+-------+----+-------|
 * |CapLock|  A | LAlt(S) |LCtl(D)|LSft(F)|LGui(G)|-----|   |-----|RGui(H)|RSft(J)|RCtl(K)|RAlt(L)|  ; |  "    |
 * |-------+----+---------+-------+-------+-------|Enter|   |Enter|-------+-------+-------+-------+----+-------|
 * |LShift |  Z |    X    |  C    |  V    |  B    |     |   |     |  N    |  M    |  ,    |  .    |  / |RShift |
 * `-------+----+---------+-------+-------+-------+-----'   `-------------+-------+-------+-------+----+-------'
 *   |LCtrl|LGui|   LAlt  | `~    | L2([) |                               | L2(]) | \     |RAlt   |RGui|RCtrl|
 *   `------------------------------------'                               `----------------------------------'
 *                                      ,-----------.           ,-----------.
 *                                      | Home|F5   |           |F11  |End  |
 *                                ,-----+-----+-----|           |-----+-----+-----.
 *                                |     |     |F8   |           |VolUp|     |     |
 *                                |Space|BkSpc|-----|           |-----|Del  |Mute |
 *                                |     |     |MO(1)|           |VolDn|     |     |
 *                                `-----------------'           `-----------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESCAPE,    KC_1,         KC_2,          KC_3,         KC_4,         KC_5,    KC_PGUP,
  KC_TAB,       KC_Q,         KC_W,          KC_E,         KC_R,         KC_T,    KC_PGDOWN,
  KC_CAPSLOCK,  KC_A,         LALT_T(KC_S),  LCTL_T(KC_D), LSFT_T(KC_F), LGUI_T(KC_G),
  KC_LSFT,      KC_Z,         KC_X,          KC_C,         KC_V,         KC_B,    KC_ENTER,
  KC_LCTRL,     KC_LGUI,      KC_LALT,       KC_GRAVE,     LT(MDIA, KC_LBRACKET),
                                                          /*Top center              Top right    */
                                                            KC_HOME,                KC_F5,
                                                                                  /*Right middle */
                                                                                    KC_F8,
                                                          /*Left btm     Center     Right btm    */
                                                           KC_SPC,       KC_BSPACE, MO(TEXTEDIT),
  // right hand
  KC_INSERT,    KC_6,         KC_7,                       KC_8,         KC_9,         KC_0,      KC_MINS,
  KC_PAUSE,     KC_Y,         KC_U,                       KC_I,         KC_O,         KC_P,      KC_EQUAL,
                RGUI_T(KC_H), RSFT_T(KC_J),	              RCTL_T(KC_K), RALT_T(KC_L), KC_SCOLON, KC_QUOTE,
  KC_ENTER,     KC_N,         KC_M,                       KC_COMM,      KC_DOT,       KC_SLASH,  KC_RSFT,
                              LT(MDIA, KC_RBRACKET),      KC_BSLASH,    KC_RALT,      KC_RGUI,   KC_RCTRL,
  /*Top left    Top center */
    KC_F11,     KC_END,
  /*Left middle */
    KC_AUDIO_VOL_UP,
  /*Left btm              Center        Right btm */
    KC_AUDIO_VOL_DOWN,    KC_DELETE,    KC_AUDIO_MUTE
),


 /* Keymap 1: Editor navigation layer
 *
 * ,----------------------------------------------------.   ,--------------------------------------------------.
 * |       |F1  |   F2    |   F3  |    F4 |   F5  |TG(3)|   |     |   F6  |   F7  |   F8  |   F9  |F10 |  F11  |
 * |-------+----+---------+-------+-------+-------+-----|   |-----+-------+-------+-------+-------+----+-------|
 * |       |    |         |       |       |       |     |   |     |   Cut |  Copy | Paste |       |    |  F12  |
 * |-------+----+---------+-------+-------+-------|     |   |     |-------+-------+-------+-------+----+-------|
 * |       |    |  LAlt   | LCtrl | LShift|  LGui |-----|   |-----|  Left |  Down |   Up  | Right |    |       |
 * |-------+----+---------+-------+-------+-------|     |   |     |-------+-------+-------+-------+----+-------|
 * |       |    |         |       |       |       |     |   |     |       |       |       |       |    |       |
 * `-------+----+---------+-------+-------+-------+-----'   `-------------+-------+-------+-------+----+-------'
 *    |    |    |         |       |       |                               |       |       |       |    |       |
 *    `-----------------------------------'                               `------------------------------------'
 *                                   ,--------------.           ,--------------.
 *                                   |      |       |           |       |      |
 *                            ,------+------+-------|           |-------+------+------.
 *                            |      |      |       |           |       |      |      |
 *                            |      |      |-------|           |-------|      |      |
 *                            |      |      |       |           |       |      |      |
 *                            `---------------------'           `---------------------'
 */
[TEXTEDIT] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      TG(WASD),
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_LALT,    KC_LCTRL,   KC_LSHIFT,  KC_LGUI,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                  /*Top center           Top right    */
                                                  KC_TRNS,               KC_TRNS,
                                                                        /*Right middle */
                                                                         KC_TRNS,
                                                  /*Left btm   Center    Right btm    */
                                                  KC_TRNS,     KC_TRNS,  KC_TRNS,
  // right hand
  KC_TRNS,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
  KC_TRNS,    RCTL(KC_X), RCTL(KC_C), RCTL(KC_V), KC_TRNS,    KC_TRNS,    KC_F12,
              KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  /*Top left    Top center */
  KC_TRNS,      KC_TRNS,
  /*Left middle */
  KC_TRNS,
  /*Left btm    Center        Right btm */
  KC_TRNS,      KC_TRNS,      KC_TRNS
),


 /* Keymap 2: Media and mouse keys
 *
 * ,----------------------------------------------------.   ,--------------------------------------------------.
 * |       |      |       |       |       |       |     |   |     |       |       |       |       |    |       |
 * |-------+------+-------+-------+-------+-------+-----|   |-----+-------+-------+-------+-------+----+-------|
 * |       |      | MsUp  |       |RClick |MsWhlUp|     |   |     |       |       |       |       |    |       |
 * |-------+------+-------+-------+-------+-------|     |   |     |-------+-------+-------+-------+----+-------|
 * |       |MsLeft|MsDown |MsRight|LClick |MsWhlDn|-----|   |-----|       |       |       |       |    |       |
 * |-------+------+-------+-------+-------+-------|     |   |     |-------+-------+-------+-------+----+-------|
 * |       |      |       |       |MClick |       |     |   |     |       |       |       |       |    |       |
 * `-------+------+-------+-------+-------+-------+-----'   `-------------+-------+-------+-------+----+-------'
 *    |    |      |       |       |       |                               |       |       |       |    |       |
 *    `-----------------------------------'                               `------------------------------------'
 *                                   ,--------------.           ,--------------.
 *                                   |      |       |           |       |      |
 *                            ,------+------+-------|           |-------+------+------.
 *                            |      |      |       |           |       |      |      |
 *                            |      |      |-------|           |-------| Pause| Next |
 *                            |      |      |       |           | PrvTr | Play | Trck |
 *                            `---------------------'           `---------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,       KC_TRNS,        KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_MS_UP,   KC_TRNS,     KC_MS_BTN2,    KC_MS_WH_UP,    KC_TRNS,
  KC_TRNS,    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_BTN1,    KC_MS_WH_DOWN,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_MS_BTN3,    KC_TRNS,        KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,
                                                   /*Top center              Top right    */
                                                   KC_TRNS,                  KC_TRNS,
                                                                           /*Right middle */
                                                                             KC_TRNS,
                                                 /*Left btm       Center     Right btm    */
                                                   KC_TRNS,       KC_TRNS,   KC_TRNS,
  // right hand
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,
              KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,
                          KC_TRNS,    KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,
  /*Top left    Top center */
  KC_TRNS,      KC_TRNS,
  /*Left middle */
  KC_TRNS,
  /*Left btm            Center                Right btm */
  KC_MEDIA_PREV_TRACK,  KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_NEXT_TRACK
),

 /* Keymap 3: WASD layer
 *
 * ,----------------------------------------------------.   ,--------------------------------------------------.
 * | Esc   |   1  |   2   |   3   |   4   |   5   | Ins |   |Pause|   6   |   7   |   8   |   9   | 0  |   -   |
 * |-------+------+-------+-------+-------+-------+-----|   |-----+-------+-------+-------+-------+----+-------|
 * | Tab   |   Q  |   W   |   E   |   R   |   T   | Del |   |TG(3)|   Y   |   U   |   I   |   O   | P  |   =   |
 * |-------+------+-------+-------+-------+-------|     |   |     |-------+-------+-------+-------+----+-------|
 * |CapLock|   A  |   S   |   D   |   F   |   G   |-----|   |-----|RGui(H)|RSft(J)|RCtl(K)|RAlt(L)| ;  |   "   |
 * |-------+------+-------+-------+-------+-------|Enter|   |Enter|-------+-------+-------+-------+----+-------|
 * | LShift|   Z  |   X   |   C   |   V   |   B   |     |   |     |   N   |   M   |   ,   |   .   | /  | RShift|
 * `-------+------+-------+-------+-------+-------+-----'   `-------------+-------+-------+-------+----+-------'
 *   |LCtrl| LGui | Alt   |  `~   | L2([) |                               | L1(]) |   \   | RAlt  |RGui| RCtrl |
 *   `------------------------------------'                               `------------------------------------'
 *                                   ,--------------.           ,--------------.
 *                                   | Home | F5    |           | F11   | End  |
 *                            ,------+------+-------|           |-------+------+------.
 *                            |      |      | F8    |           | VolUp |      |      |
 *                            | Space|BkSpc |-------|           |-------| Del  | Mute |
 *                            |      |      | MO(1) |           | VolDn |      |      |
 *                            `---------------------'           `---------------------'
 */
[WASD] = LAYOUT_ergodox(
  // left hand
  KC_ESCAPE,    KC_1,         KC_2,          KC_3,         KC_4,         KC_5,    KC_INSERT,
  KC_TAB,       KC_Q,         KC_W,          KC_E,         KC_R,         KC_T,    KC_DELETE,
  KC_CAPSLOCK,  KC_A,         KC_S,          KC_D,         KC_F,         KC_G,
  KC_LSFT,      KC_Z,         KC_X,          KC_C,         KC_V,         KC_B,    KC_ENTER,
  KC_LCTRL,     KC_QUOT,      KC_LALT,       KC_GRAVE,     LT(MDIA, KC_LBRACKET),
                                                          /*Top center              Top right    */
                                                            KC_HOME,                KC_F5,
                                                                                  /*Right middle */
                                                                                    KC_F8,
                                                          /*Left btm     Center     Right btm    */
                                                           KC_SPC,       KC_BSPACE, MO(TEXTEDIT),
  // right hand
  KC_PAUSE,     KC_6,         KC_7,          KC_8,         KC_9,         KC_0,      KC_MINS,
  TG(WASD),     KC_Y,         KC_U,          KC_I,         KC_O,         KC_P,      KC_EQUAL,
                RGUI_T(KC_H), RSFT_T(KC_J),	 RCTL_T(KC_K), RALT_T(KC_L), KC_SCOLON,	KC_QUOTE,
  KC_ENTER,     KC_N,         KC_M,          KC_COMM,      KC_DOT,       KC_SLASH,  KC_RSFT,
                              KC_RBRACKET,   KC_BSLASH,    KC_RALT,      KC_RGUI,   KC_RCTRL,
  /*Top left    Top center */
    KC_F11,     KC_END,
  /*Left middle */
    KC_AUDIO_VOL_UP,
  /*Left btm              Center        Right btm */
    KC_AUDIO_VOL_DOWN,    KC_DELETE,    KC_AUDIO_MUTE
)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
