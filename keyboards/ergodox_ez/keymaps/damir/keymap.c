#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"

//TAP DANCE
int IS_CAPS = 0;
enum {
  // TD_SHIFT_CAPS = 0,
  TD_ESC_TILDE,
  // TD_RESET,
  // TD_UP_SLASH
};

// void dance_fc_finished (qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     register_code (KC_LSHIFT);
//   }else if (state->count == 2) {
//     if (IS_CAPS == 0) {
//       register_code (KC_LSHIFT);
//       IS_CAPS = 1;
//       ergodox_right_led_3_on();
//     }else{
//       unregister_code (KC_LSHIFT);
//       IS_CAPS = 0;
//     }
//   }
// }

// void dance_fc_reset (qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     unregister_code (KC_LSHIFT);
//     ergodox_right_led_3_off();
//   }
// }


//Tap Dance Definitions/
qk_tap_dance_action_t tap_dance_actions[] = {
  // [TD_SHIFT_CAPS]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fc_finished, dance_fc_reset),
  [TD_ESC_TILDE]  = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_ESC),
  // [TD_RESET]  = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, RESET),
  // [TD_UP_SLASH] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_SLASH)
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
#define ARROWS_RIGHT 5 //arrow keys on the right side

#define RGBLIGHT_COLOR_LAYER_0 24, 24, 24
#define RGBLIGHT_COLOR_LAYER_1 255, 0, 0
#define RGBLIGHT_COLOR_LAYER_2 0, 255, 0
#define RGBLIGHT_COLOR_LAYER_3 0, 0, 255
#define RGBLIGHT_COLOR_LAYER_4 255, 255, 0
#define RGBLIGHT_COLOR_LAYER_5 255, 0, 255
#define RGBLIGHT_COLOR_LAYER_6 0, 255, 255
#define RGBLIGHT_COLOR_LAYER_7 255, 255, 255

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
http://www.keyboard-layout-editor.com/#/gists/e755fe951b6529b96e9958511b33dc71
 */
  [BASE] = LAYOUT_ergodox(
    TD(TD_ESC_TILDE),           KC_1,                   KC_2,                   KC_3,               KC_4,               KC_5,                 KC_ESCAPE,        //7
    KC_TAB,                     KC_Q,                   KC_W,                   KC_E,               KC_R,               KC_T,                 TT(ARROWS_RIGHT),                      //7
    LT(SYMBOLS,KC_CAPSLOCK),    KC_A,                   KC_S,                   KC_D,               KC_F,               KC_G,                             //6
    KC_LSHIFT,                  ALT_T(KC_Z),            GUI_T(KC_X),            KC_C,               KC_V,               KC_B,                 KC_H,      //7
    KC_LCTL,                    KC_LALT,                KC_LGUI,                KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  //5
                                                                                                    KC_SPACE,           TG(CONSOLE),
                                                                                                                        KC_MINUS,            //3
                                                                                GUI_T(KC_SPACE),    LT(ARROWS_RIGHT,KC_BSPACE),KC_DELETE,                        //3

    KC_6,                       KC_7,                   KC_8,                   KC_9,               KC_0,               KC_MINUS,             KC_BSPACE,
    KC_EQUAL,                   KC_Y,                   KC_U,                   KC_I,               KC_O,               KC_P,                 KC_QUOTE,
                                KC_H,                   KC_J,                   KC_K,               KC_L,               KC_SCOLON,            LT(MOUSE,KC_ENTER),
    TG(SYMBOLS),                KC_N,                   KC_M,                   KC_COMMA,           KC_DOT,             KC_SLASH,             KC_RSHIFT,
    KC_RGUI,                    KC_LEFT,                KC_DOWN,                KC_UP,              KC_RIGHT,
    KC_MEDIA_PREV_TRACK,        KC_MEDIA_NEXT_TRACK,
    TG(MOUSE),
    KC_MEDIA_PLAY_PAUSE,        LT(SYMBOLS,KC_BSLASH),  LT(ARROWS,KC_SPACE)
  ),

  [SYMBOLS] = LAYOUT_ergodox(
    KC_ESCAPE,                  KC_F1,                  KC_F2,                  KC_F3,              KC_F4,              KC_F5,                KC_F6,
    KC_NO,                      KC_EXLM,                KC_AT,                  KC_LCBR,            KC_RCBR,            KC_PIPE,              KC_NO,
    KC_NO,                      KC_HASH,                KC_DLR,                 KC_LPRN,            KC_RPRN,            KC_GRAVE,
    SFT_T(KC_NO),               KC_PERC,                KC_CIRC,                KC_LBRACKET,        KC_RBRACKET,        KC_TILD,              KC_NO,
    KC_NO,                      KC_NO,                  KC_AUDIO_MUTE,          KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,
                                                                                                    RGB_MOD,            RGB_RMOD,
                                                                                                                        RGB_HUI,
                                                                                RGB_VAD,            RGB_VAI,            RGB_HUD,

    KC_F7,                      KC_F8,                  KC_F9,                  KC_F10,             KC_F11,             KC_F12,               KC_BSPACE,
    KC_TRANSPARENT,             KC_UP,                  KC_7,                   KC_8,               KC_9,               KC_KP_ASTERISK,       KC_DELETE,
                                KC_DOWN,                KC_4,                   KC_5,               KC_6,               KC_KP_MINUS,          KC_KP_ENTER,
    KC_TRANSPARENT,             KC_AMPR,                KC_1,                   KC_2,               KC_3,               KC_KP_SLASH,          SFT_T(KC_KP_PLUS),
    KC_KP_0,                    KC_KP_0,                KC_KP_DOT,              KC_EQUAL,           KC_KP_ENTER,
    RGB_TOG,                    RGB_M_T,
    RGB_M_P,
    RGB_SAD,                    KC_TRANSPARENT,         RGB_SAI
  ),

  [ARROWS] = LAYOUT_ergodox(
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,       KC_TRANSPARENT,        //7
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,       KC_TRANSPARENT,                      //7
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                             //6
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,       KC_TRANSPARENT,      //7
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,  //5
                                                                                                    KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                        //3
                                                                                KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                        //3

    KC_NO,                      KC_NO,                  KC_PSCREEN,             KC_SLCK,            KC_PAUSE,           KC_BSPACE,            KC_DELETE,
    KC_NO,                      KC_HOME,                KC_END,                 KC_UP,              KC_PGUP,            KC_PGDOWN,            KC_AUDIO_VOL_UP,
                                KC_NO,                  KC_LEFT,                KC_DOWN,            KC_RIGHT,           KC_NO,                KC_AUDIO_VOL_DOWN,
    KC_NO,                      KC_MS_WH_LEFT,          KC_MS_WH_DOWN,          KC_MS_WH_UP,        KC_MS_WH_RIGHT,     KC_NO,                SFT_T(KC_MEDIA_PLAY_PAUSE),
    KC_AUDIO_VOL_DOWN,          KC_AUDIO_VOL_UP,        KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,
    KC_MEDIA_PREV_TRACK,        KC_MEDIA_NEXT_TRACK,
    KC_MEDIA_STOP,
    KC_MEDIA_PLAY_PAUSE,        KC_NO,                  KC_NO
  ),

  [MOUSE] = LAYOUT_ergodox(
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_ASUP,              KC_ASON ,        //7
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_ASDN,              KC_ASOFF,                      //7
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_ASRP,                                    //6
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,       KC_TRANSPARENT,      //7
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,  //5
                                                                                                    KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                        //3
                                                                                KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                        //3

    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,  KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_MS_UP,           KC_TRANSPARENT,       KC_TRANSPARENT,
                                KC_TRANSPARENT,         KC_TRANSPARENT,         KC_MS_LEFT,         KC_MS_DOWN,         KC_MS_RIGHT,          KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_MS_ACCEL2,           KC_MS_WH_LEFT,          KC_MS_WH_DOWN,      KC_MS_WH_UP,        KC_MS_WH_RIGHT,       KC_TRANSPARENT,
    KC_MS_ACCEL0,               KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,        KC_TRANSPARENT,     KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_MS_BTN2,                 KC_MS_BTN3,             KC_MS_BTN1
  ),
  [CONSOLE] = LAYOUT_ergodox(
    TERM_ON,                    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,       RESET,        //7
    TERM_OFF,                   KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,       KC_TRANSPARENT,                       //7
    VRSN,                       KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                   //6
    KC_LSHIFT,                  KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,       KC_TRANSPARENT,      //7
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,  //5
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,                        //3
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,                        //3

    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,       KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,       KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,       KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT
  ),
  [ARROWS_RIGHT] = LAYOUT_ergodox(
    KC_NO,                      KC_NO,                  KC_NO,                  KC_NO,              KC_NO,              KC_NO,                KC_NO,        //7
    KC_NO,                      KC_HOME,                KC_END,                 KC_UP,              KC_PGUP,            KC_PGDOWN,            KC_TRANSPARENT,                      //7
    KC_NO,                      KC_NO,                  KC_LEFT,                KC_DOWN,            KC_RIGHT,           KC_NO,                             //6
    KC_LSHIFT,                  KC_LGUI,                KC_MS_WH_LEFT,          KC_MS_WH_UP,        KC_MS_WH_DOWN,      KC_MS_WH_RIGHT,       KC_ENTER,      //7
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,  //5
                                                                                                    KC_TRANSPARENT,     KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                        //3
                                                                                KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,                        //3

    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,  KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_MS_UP,           KC_TRANSPARENT,       KC_TRANSPARENT,
                                KC_TRANSPARENT,         KC_TRANSPARENT,         KC_MS_LEFT,         KC_MS_DOWN,         KC_MS_RIGHT,          KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_MS_ACCEL2,           KC_MS_WH_LEFT,          KC_MS_WH_DOWN,      KC_MS_WH_UP,        KC_MS_WH_RIGHT,       KC_TRANSPARENT,
    KC_MS_ACCEL0,               KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,        KC_TRANSPARENT,     KC_TRANSPARENT,
    KC_TRANSPARENT,             KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_MS_BTN2,                 KC_MS_BTN3,             KC_MS_BTN1
  )
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
  rgblight_disable();
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  #ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_enable_noeeprom();
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
  #endif
};
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }
    if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // uprint("test uprint");
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
void matrix_scan_user(void) {
  // timer_count++
}
uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    // ergodox_board_led_off();
    // ergodox_right_led_1_off();
    // ergodox_right_led_2_off();
    // ergodox_right_led_3_off();
    // rgblight_disable_noeeprom();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          // rgblight_enable_noeeprom();
          // rgblight_disable_noeeprom();
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        // ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          // rgblight_enable_noeeprom();
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        // ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          // rgblight_enable_noeeprom();
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
       #endif
        break;
      case 3:
        // ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          // rgblight_enable_noeeprom();
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        // ergodox_right_led_1_on();
        // ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          // rgblight_enable_noeeprom();
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        // ergodox_right_led_1_on();
        // ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          // rgblight_enable_noeeprom();
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        // ergodox_right_led_2_on();
        // ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          // rgblight_enable_noeeprom();
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        // ergodox_right_led_1_on();
        // ergodox_right_led_2_on();
        // ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          // rgblight_enable_noeeprom();
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }
    return state;

};
