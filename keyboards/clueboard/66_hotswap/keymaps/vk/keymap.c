#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
#define _OSX 0
#define _WIN 1
#define _FL 2
#define _CL 3
#define _ML 4

enum custom_keycodes {
    S_GAME = SAFE_RANGE,
    OSX,
    WIN,
    KC_RUNE,
    DYNAMIC_MACRO_RANGE
};

// This file must be included after DYNAMIC_MACRO_RANGE is defined...
#include "dynamic_macro.h"

#ifdef AUDIO_ENABLE
  float song_game[][2] = SONG(SONIC_RING);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _OSX: Base Layer (Default Layer)
   */
[_OSX] = LAYOUT(
  KC_GESC,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,     KC_BSPC,        LT(_ML,KC_GRAVE),
  KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,                KC_DEL,
  LT(_FL, KC_CAPS),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_ENT,
  KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,        KC_UP,
  KC_LCTL,KC_LALT,KC_LGUI,        KC_SPC, KC_SPC,                         KC_HENK,KC_RGUI,MO(_FL),KC_RALT,KC_LEFT,KC_DOWN,KC_RGHT),

[_WIN] = LAYOUT(
  KC_GESC,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,        LT(_ML,KC_GRAVE),
  KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,                KC_DEL,
  LT(_FL, KC_CAPS),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_ENT,
  KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,        KC_UP,
  KC_LCTL,KC_LGUI,KC_LALT,        KC_SPC, KC_SPC,                         KC_HENK,KC_RALT,MO(_FL),KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
  KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,KC_DEL,         KC_VOLU,
  _______,_______,_______,_______,_______,_______,_______,_______,_______,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_MUTE,                KC_VOLD,
  _______,_______,MO(_CL),_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
  _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,          _______,        KC_PGUP,
  _______,_______,_______,        _______,_______,                        _______,_______,MO(_FL),_______,KC_HOME,KC_PGDN,KC_END),

  /* Keymap _CL: Control layer
   */
[_CL] = LAYOUT(
  BL_STEP,RGB_M_P,RGB_M_B,RGB_M_R,RGB_M_SW,RGB_M_SN,RGB_M_K,RGB_M_X,RGB_M_G,_______,_______,_______,_______,RGB_TOG,        RGB_VAI,
  CK_TOGG,_______,_______,_______,RESET,  _______,_______,_______,_______,_______,_______,_______,_______,_______,                RGB_VAD,
  _______,_______,MO(_CL),_______,_______,_______,_______,_______,_______,_______,_______,_______,S_GAME,
  MO(_FL),        _______,_______,_______,_______,_______,_______,_______,OSX,WIN,_______,        _______,        RGB_SAI,
  _______,_______,_______,        RGB_MOD,   RGB_MOD,                     _______,_______,MO(_FL),_______,RGB_HUD,RGB_SAD,RGB_HUI),

  /* macro controls
  */
[_ML] = LAYOUT(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_RUNE,        _______,
  _______,_______,_______,_______,_______,  _______,_______,_______,_______,_______,_______,_______,DYN_REC_START1,DYN_MACRO_PLAY1,        LGUI(LCTL(LSFT(KC_4))),
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
  _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,        _______,
  _______,_______,_______,        _______,   _______,                     _______,_______,_______,_______,_______,_______,_______),
};

bool rs_click;
uint16_t rs_timer = false;
uint16_t rs_interval;

void matrix_init_user(void) {
    rs_timer = false;
    rs_interval = 1000 + ( rand() % 100 );
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint16_t macro_kc = (keycode == LT(_ML,KC_GRAVE) ? DYN_REC_STOP : keycode);

    if (!process_record_dynamic_macro(macro_kc, record)) {
        return false;
    }

    switch (keycode) {
        case OSX:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_OSX);
          }
          return false;
          break;
        case WIN:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_WIN);
          }
          return false;
          break;
        case S_GAME:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_game);
            }
            return false;
            break;
        case KC_RUNE:
            if (record->event.pressed) {
                rs_click ^= 1;
                rs_timer = timer_read();
            }
            return false;
            break;
    }
  return true; 
}

void matrix_scan_user(void) {
  if (rs_click) {
    if (timer_elapsed(rs_timer) >= rs_interval) {
      SEND_STRING(SS_TAP(X_KP_5));
      //xprintf("Interval: %u\n", rs_interval);
      rs_timer = timer_read();
      rs_interval = 1000 + ( rand() % 500 );
    }
  }
}
