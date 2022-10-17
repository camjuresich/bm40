/* Copyright 2020 tominabox1
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
#include "features/layer_lock.h"

enum layers {
  _COLEMAK,
  _NUM,
  _SNUM,
  _ARROWL,
  _ARROWR
};

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
  // Other custom keys...
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
  // Your macros ...

  return true;
}

// #define LOWER MO(_LOWER)
#define NUM LT(_NUM, KC_EQL)
#define SNUM LT(_SNUM, KC_MINUS)
#define ARROWL LT(_ARROWL, KC_CAPS)
#define ARROWR LT(_ARROWR, KC_QUOT)
#define OSFT OSM(MOD_LSFT)
#define OCTL OSM(MOD_LCTL)
#define OALT OSM(MOD_LALT)
#define RENTER MT(MOD_RSFT, KC_ENTER) 
#define RIGHT KC_RIGHT 
#define DOWN KC_DOWN
#define LEFT  KC_LEFT
#define UP KC_UP
#define CLEFT C(KC_LEFT)
#define CRIGHT C(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,     KC_B,     KC_J,  KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSPC,
        ARROWL,  KC_A,    KC_R,    KC_S,    KC_T,     KC_G,     KC_M,  KC_N,    KC_E,    KC_I,    KC_O,     ARROWR,
        OSFT,    KC_Z,    KC_X,    KC_C,    KC_D,     KC_V,     KC_K,  KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  RENTER ,
        OCTL,    OALT,    KC_ESC,  KC_LGUI, NUM,         KC_SPACE,     SNUM,    KC_LGUI, KC_DEL,  OALT,     OCTL
    ),

    [_NUM] = LAYOUT_planck_mit(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_1,   KC_2,   KC_3,    LLOCK, KC_BSPC,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_4,   KC_5,   KC_6,    KC_LPRN, KC_RPRN,
        KC_TRNS, _______, _______, _______, _______, _______, _______, KC_7,   KC_8,   KC_9,    _______, _______,
        KC_TRNS,  KC_TRNS, LLOCK, _______, KC_TRNS,      KC_TRNS,      KC_0,   KC_DOT, KC_COMM, _______, _______  
    ),

    [_SNUM] = LAYOUT_planck_mit(
        S(KC_LBRC), S(KC_RBRC), S(KC_1), S(KC_2), S(KC_3), _______, _______, _______, _______, _______, _______, KC_BSPC,
        KC_LPRN,    KC_RPRN,    S(KC_4), S(KC_5), S(KC_6), _______, _______, _______, _______, _______, _______, _______,
        KC_LBRC,    KC_RBRC,    S(KC_7), S(KC_8), S(KC_9), _______, _______, _______, _______, _______, _______, _______,
        _______,    _______,    LLOCK, _______, S(KC_0),      KC_TRNS,       KC_TRNS, _______, _______, _______, _______
    ),

    [_ARROWL] = LAYOUT_planck_mit(
        _______, _______, KC_UP,   LLOCK,   _______, _______,  _______,  _______, _______, KC_PSCR,    KC_DEL,  KC_BSPC,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,  _______,  KC_HOME, KC_PGUP, KC_PGDN,    KC_END,  KC_GRAVE,
        _______, CLEFT,   _______, CRIGHT,  _______, _______,  _______,  _______, _______, S(KC_BSLS), KC_BSLS, KC_TILD,
        KC_TRNS, KC_TRNS, LLOCK,   KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS
    ),

    [_ARROWR] = LAYOUT_planck_mit(
        RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_TOG, _______,  RESET,    _______, LLOCK,   KC_UP,   _______,  KC_BSPC,
        RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______,  _______,  _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS,
        _______, _______, _______, _______, _______, _______,  _______,  _______, CLEFT,   _______, CRIGHT,   _______,
        KC_TRNS, KC_TRNS, LLOCK,   KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
    )

};

// S(KC_LPRN), S(KC_RPRN),
// KC_LBRC,    KC_RBRC,   
// S(KC_LBRC), S(KC_RBRC),

// _______, _______, KC_UP,   _______,
// KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT,
// _______, CLEFT,   _______, CRIGHT, 
// RESET,   DEBUG,   _______, _______,
//         KC_LT,      KC_GT,      KC_1,    KC_2,    KC_3, _______,  _______,  _______, _______, _______, _______, KC_BSPC,
//         KC_TRNS,    KC_RPRN,    KC_4,    KC_5,    KC_6, _______,  _______,  _______, _______, KC_PSCR, KC_DEL,  _______,
//         KC_LBRC,    KC_RBRC,    KC_7,    KC_8,    KC_9, KC_BSLS,  _______,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
//         S(KC_LBRC), S(KC_RBRC), _______, _______, KC_0,       KC_TRNS,      _______, _______, _______, _______, _______

        // _______, _______, KC_UP,   _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_TOG, _______, KC_BSPC,
        // KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, KC_GRAVE,
        // _______, CLEFT,   _______, CRIGHT,  _______, _______, _______, _______, _______, _______, _______, KC_TILD,
        // RESET,   DEBUG,   _______, _______, KC_LCTL,      KC_TRNS,     _______, _______, _______, _______, _______  

