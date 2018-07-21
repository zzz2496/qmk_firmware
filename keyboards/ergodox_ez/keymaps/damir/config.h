// Sets good default for the speed of the mouse.
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    40
#define MOUSEKEY_MAX_SPEED      8

#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_DELAY

#define MOUSEKEY_WHEEL_MAX_SPEED    0
#define MOUSEKEY_WHEEL_TIME_TO_MAX  255
#define MOUSEKEY_WHEEL_DELTA        0

#undef TAPPING_TOGGLE
#undef TAPPING_TERM
#undef IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_TOGGLE  1

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

#define TAPPING_TERM    170
// #define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
#define PERMISSIVE_HOLD
/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)) || \
    keyboard_report->mods == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)) \
)
/* number of backlight levels */
#define BACKLIGHT_LEVELS 3

#ifndef LED_BRIGHTNESS_LO
#define LED_BRIGHTNESS_LO       15
#endif
#ifndef LED_BRIGHTNESS_HI
#define LED_BRIGHTNESS_HI       255
#endif
#define LED_BRIGHTNESS_DEFAULT (LED_BRIGHTNESS_HI)

/* ws2812 RGB LED */
#define RGB_DI_PIN D7
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 15     // Number of LEDs
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 22
#define RGBLIGHT_VAL_STEP 8

#define NO_DEBUG
#define USER_PRINT
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT 160