/* Copyright 2020 Hannes Hasselbring
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


// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY,
  _RAISE,
  _LOWER,
  _ADDITION

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* OWERTY
 * |-----------------------------------------------------.                    .-----------------------------------------------------|
 * |KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC  |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT |
 * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
 *                         KC_NO, KC_NO, KC_LGUI,   LOWER,  KC_SPC|  |  KC_ENT,  RAISE,  KC_RALT, KC_NO, KC_NO
 *                                       |------------------------|  |--------------------------|
 */
[_QWERTY] = LAYOUT_void_ergo(
 /* 0,0         0,1 */
    KC_TAB,     KC_Q,     KC_W,     KC_E,       KC_R,     KC_T,                     KC_Y,       KC_U,     KC_I,       KC_O,     KC_P,     KC_BSPC,
    KC_LSFT,    KC_A,     KC_S,     KC_D,       KC_F,     KC_G,                     KC_H,       KC_J,     KC_K,       KC_L,     KC_SCLN,  KC_QUOT,
    KC_LCTL,    KC_Z,     KC_X,     KC_C,       KC_V,     KC_B,                     KC_N,       KC_M,     KC_COMM,    KC_DOT,   KC_SLSH,  KC_ENTER,
/*           3,1(rotrary) 3,2       3,3         3,4       3,5                       3,6         3,7       3,8         3,9       3,10 (rotary)*/
                KC_MPLY,  KC_LALT,  KC_LGUI, LT(_LOWER, KC_SPACE), LT(_ADDITION, KC_LBRACKET),       LT(_ADDITION, KC_RBRACKET),   LT(_RAISE, KC_SPC),   KC_RGUI, KC_RALT,  KC_MUTE
),



[_LOWER] = LAYOUT_void_ergo(
    KC_ESC,     KC_EXLM,  KC_AT,    KC_HASH,    KC_DLR,   KC_PERC,                  KC_CIRC,    KC_AMPR,     KC_ASTR,    KC_LPRN,  KC_RPRN,  KC_DELETE,
    KC_TRNS,    KC_UP,  KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,                  KC_LEFT,    KC_DOWN,     KC_UP,      KC_RIGHT, KC_TRNS,  KC_TRNS,
    KC_LEFT,    KC_DOWN,  KC_RIGHT,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,  KC_LGUI,  MO(_LOWER), KC_SPC,   RESET,                  KC_TRNS,    KC_ENT,      MO(_RAISE), KC_RALT,  KC_TRNS
),

[_RAISE] = LAYOUT_void_ergo(
    KC_ESC,     KC_1,     KC_2,     KC_3,       KC_4,     KC_5,                     KC_6,       KC_7,     KC_8,       KC_9,     KC_0,     KC_DELETE,
    KC_TRNS,    LCAG(KC_LEFT),  LCAG(KC_RIGHT),  LCAG(KC_M),    KC_TRNS,  KC_TRNS,                  KC_MINS,    KC_EQL,   KC_LCBR,    KC_RCBR,  KC_PIPE,  KC_GRV,
    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_UNDS,    KC_PLUS,  KC_LBRC,    KC_RBRC,  KC_BSLS,  KC_TILD,
                KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,                  KC_TRNS,    KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS
),

[_ADDITION] = LAYOUT_void_ergo(
    KC_ESC,     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                             KC_F6,    KC_F7,  KC_F8,    KC_F9,  KC_F10,  KC_TRNS,
    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  RESET,                    RESET,      KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS
)




};
// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

/*
 * ROTARY ENCODER
 */

static bool tabbing = false;
static uint16_t tabtimer;
#define TABBING_TIMER 750

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }
        tap_code(KC_TAB);
      } else {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }

        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
    } else {
      if (clockwise) {
        tap_code(KC_UP);
      } else {
        tap_code(KC_DOWN);
      }
    }
  }
  else if (index == 1) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }
        tap_code(KC_TAB);
      } else {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }

        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
    } else {
      if (clockwise) {
        tap_code(KC_RIGHT);
      } else {
        tap_code(KC_LEFT);
      }
    }
  }
}

void matrix_scan_user(void) {
  if(tabbing) {
    if (timer_elapsed(tabtimer) > TABBING_TIMER) {
      unregister_code(KC_LALT);
      tabbing = false;
    }
  }
}

void matrix_init_user(void) {

}
