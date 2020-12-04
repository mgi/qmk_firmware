/* Copyright 2018 Manuel Giraud
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
#include "xd75.h"
#include "keymap_bepo.h"

// Layer shorthand
#define _BP 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BP] = {{ BP_DOLLAR, BP_DQOT,    BP_LGIL,    BP_RGIL, BP_LPRN, BP_RPRN,    KC_TRNS, BP_AT,   BP_PLUS , BP_MINUS, BP_SLASH, BP_ASTR, BP_EQUAL, BP_PERCENT, KC_VOLU },
		 { KC_TAB,    BP_B,       BP_E_ACUTE, BP_P,    BP_O,    BP_E_GRAVE, KC_BSPC, BP_DCRC, BP_V,     BP_D,     BP_L,     BP_J,    BP_Z,     BP_W,       KC_VOLD },
		 { KC_LSFT,   BP_A,       BP_U,       BP_I,    BP_E,    BP_COMMA,   KC_ENT,  BP_C,    BP_T,     BP_S,     BP_R,     BP_N,    BP_M,     KC_RSFT,    KC_MPLY },
		 { KC_ESC,    BP_A_GRAVE, BP_Y,       BP_X,    BP_DOT,  BP_K,       KC_TRNS, BP_APOS, BP_Q,     BP_G,     BP_H,     BP_F,    BP_CCED,  KC_TRNS,    KC_MNXT },
		 { MO(_FN),   KC_TRNS,    KC_TRNS,    KC_LGUI, KC_LALT, KC_LCTL,    KC_SPC,  KC_RCTL, KC_LALT,  BP_ALGR,  KC_LEFT,  KC_DOWN, KC_UP,    KC_RGHT,    KC_MPRV }},

	[_FN] = {{ KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_SLSH,  KC_ASTR,  KC_TRNS, KC_TRNS,  KC_TRNS,    RESET   },
		 { RGB_MOD,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_P7,    KC_P8,    KC_P9,    KC_MINS, KC_TRNS,  KC_TRNS,    KC_TRNS },
		 { RGB_TOG,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_P4,    KC_P5,    KC_P6,    KC_PLUS, KC_TRNS,  KC_TRNS,    KC_TRNS },
		 { KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_P1,    KC_P2,    KC_P3,    KC_ENT,  KC_TRNS,  KC_TRNS,    KC_TRNS },
		 { MO(_FN),   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_P0,    KC_TRNS,  KC_PDOT,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS }}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
