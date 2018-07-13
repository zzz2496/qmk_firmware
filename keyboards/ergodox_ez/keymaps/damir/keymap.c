#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"

//TAP DANCE
int IS_CAPS = 0;
enum {
  TD_SHIFT_CAPS = 0,
  TD_ESC_TILDE,
  TD_RESET,
  TD_UP_SLASH
};

void dance_fc_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LSHIFT);
  }else if (state->count == 2) {
    if (IS_CAPS == 0) {
      register_code (KC_LSHIFT);
      IS_CAPS = 1;
      ergodox_right_led_3_on();
    }else{
      unregister_code (KC_LSHIFT);
      IS_CAPS = 0;
    }
  }
}

void dance_fc_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LSHIFT);
    ergodox_right_led_3_off();
  }
}


//Tap Dance Definitions/
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SHIFT_CAPS]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fc_finished, dance_fc_reset),
  [TD_ESC_TILDE]  = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_ESC),
  [TD_RESET]  = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, RESET),
  [TD_UP_SLASH] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_SLASH)
// Other declarations would go here, separated by commas, if you have them
};

//In Layer declaration, add tap dance item in place of a key code
// TD(TD_SHIFT_CAPS)

//TAP DANCE


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,

};
#define BASE 0 // default layer
#define SYMBOLS 1 // symbols
#define ARROWS 2 //arrow keys
#define MOUSE 3 //console related keys
#define CONSOLE 4 //console related keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [BASE] = LAYOUT_ergodox(
    TD(TD_ESC_TILDE),           KC_1,             KC_2,           KC_3,               KC_4,           KC_5,           KC_ESCAPE,        //7
    KC_TAB,                     KC_Q,             KC_W,           KC_E,               KC_R,           KC_T,           MO(1),                      //7
    LT(ARROWS,KC_BSPACE),       KC_A,             KC_S,           KC_D,               KC_F,           KC_G,                             //6
    KC_LSHIFT,                  ALT_T(KC_Z),      GUI_T(KC_X),    KC_C,               KC_V,           KC_B,           KC_H,      //7
    // TD(TD_SHIFT_CAPS),ALT_T(KC_Z),GUI_T(KC_X),KC_C,KC_V,KC_B,KC_H,      //7
    KC_LCTL,                    KC_LALT,          KC_LGUI,        KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  //5
    KC_SPACE,                   KC_CAPSLOCK,      TG(4),                        //3
    GUI_T(KC_SPACE),            KC_BSPACE,        KC_DELETE,                        //3

    KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_BSPACE,
    KC_EQUAL,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,
    KC_H,KC_J,KC_K,KC_L,KC_SCOLON,LT(3,KC_ENTER),
    TG(1),KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,
    KC_RGUI,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,
    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,
    TG(3),KC_MEDIA_PLAY_PAUSE,
    LT(1,KC_QUOTE),LT(2,KC_SPACE)
  ),

  [SYMBOLS] = LAYOUT_ergodox(
    KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,
    KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRAVE,
    SFT_T(KC_NO),KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_MUTE,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,
    KC_LEFT,KC_RIGHT,KC_TRANSPARENT,
    RGB_VAD,RGB_VAI,KC_TRANSPARENT,

    KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_BSPACE,
    KC_TRANSPARENT,KC_UP,KC_7,KC_8,KC_9,KC_KP_ASTERISK,KC_DELETE,
    KC_DOWN,KC_4,KC_5,KC_6,KC_KP_MINUS,KC_KP_ENTER,
    KC_TRANSPARENT,KC_AMPR,KC_1,KC_2,KC_3,KC_KP_SLASH,SFT_T(KC_KP_PLUS),
    KC_KP_0,KC_KP_0,KC_KP_DOT,KC_EQUAL,KC_KP_ENTER,
    RGB_TOG,RGB_SLD,RGB_MOD,
    RGB_HUD,KC_TRANSPARENT,KC_TRANSPARENT
  ),

  [ARROWS] = LAYOUT_ergodox(
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_MS_WH_LEFT,KC_MS_UP,KC_MS_WH_RIGHT,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,
    // KC_LSHIFT,KC_LALT,KC_MS_WH_UP,KC_MS_WH_DOWN,KC_TRANSPARENT,KC_MS_ACCEL0,KC_TRANSPARENT,
    // KC_LCTL,KC_LGUI,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_LGUI,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_MS_BTN1,KC_MS_BTN3,KC_MS_BTN2,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

    KC_TRANSPARENT,KC_TRANSPARENT,KC_PSCREEN,KC_SLCK,KC_PAUSE,KC_BSPACE,KC_DELETE,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_UP,KC_PGUP,KC_TRANSPARENT,KC_AUDIO_VOL_UP,
    KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_END,KC_TRANSPARENT,KC_PGDOWN,KC_TRANSPARENT,SFT_T(KC_MEDIA_PLAY_PAUSE),
    KC_INSERT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_ACCEL1,KC_MS_ACCEL2,
    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,
    KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_TRANSPARENT

    // KC_TRANSPARENT,KC_TRANSPARENT,KC_PSCREEN,KC_SLCK,KC_PAUSE,KC_BSPACE,KC_DELETE,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_UP,
    // KC_INSERT,KC_HOME,KC_UP,KC_PGUP,KC_TRANSPARENT,KC_AUDIO_VOL_DOWN,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_RALT,SFT_T(KC_MEDIA_PLAY_PAUSE),
    // KC_END,KC_TRANSPARENT,KC_PGDOWN,KC_MS_ACCEL1,KC_MS_ACCEL2,
    // KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,
    // KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_TRANSPARENT
  ),

  [MOUSE] = LAYOUT_ergodox(
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_UP,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_UP,KC_MS_WH_RIGHT,KC_TRANSPARENT,
    KC_MS_ACCEL0,KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_MS_BTN2,KC_MS_BTN3,KC_MS_BTN1

    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MS_WH_LEFT,KC_MS_UP,
    // KC_MS_WH_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_WH_DOWN,KC_MS_WH_UP,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_ACCEL0,KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_MS_BTN2,KC_MS_BTN3,KC_MS_BTN1
  ),
  [CONSOLE] = LAYOUT_ergodox(
    // TERM_ON,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RESET,
    // TERM_OFF,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_ENTER,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    // KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT
    TERM_ON,KC_1,KC_2,KC_3,KC_4,KC_5,RESET,        //7
    TERM_OFF,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TRANSPARENT,                       //7
    VRSN,KC_A,KC_S,KC_D,KC_F,KC_G,                             //6
    KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_H,      //7
    KC_LCTL,KC_LALT,KC_LGUI,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,  //5
    KC_SPACE,KC_CAPSLOCK,KC_TRANSPARENT,                        //3
    KC_LGUI,KC_BSPACE,KC_DELETE,                        //3

    KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_BSPACE,
    KC_EQUAL,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,
    KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_ENTER,
    KC_TRANSPARENT,KC_N,KC_M,KC_COMMA,KC_DOT,KC_UP,KC_RSHIFT,
    KC_RGUI,KC_SLASH,KC_LEFT,KC_DOWN,KC_RIGHT,
    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,
    KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,
    KC_QUOTE,KC_SPACE
  ),

};
#define TERMINAL_HELP
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
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
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
