/* Copyright 2020 Neil Brian Ramirez
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
		KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
		KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
		KC_LCTL,  KC_LALT,   	    KC_SPC,  MO(1),                     KC_SPC,                    KC_RGUI, KC_LCTL,
		KC_VOLD,  KC_VOLU,
    ),
    [1] = LAYOUT(
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,   KC_TRNS,   	    KC_TRNS, KC_TRNS,                   KC_TRNS,                    KC_TRNS,KC_TRNS,    
		KC_TRNS,   KC_TRNS, 
    ),
    [2] = LAYOUT(
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,   KC_TRNS,   	    KC_TRNS, KC_TRNS,                   KC_TRNS,                    KC_TRNS,KC_TRNS,    
		KC_TRNS,   KC_TRNS,   
    ),
    [3] = LAYOUT(
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,   KC_TRNS,   	    KC_TRNS, KC_TRNS,                   KC_TRNS,                    KC_TRNS,KC_TRNS,    
		KC_TRNS,   KC_TRNS,  
    ),
};

/* E00A is row 2 col 0 (see LAYOUT) */
keyevent_t encoder2_cw  = {
    .key = (keypos_t){.row = 4, .col = 1},
    .pressed = false
};
/* E00B is row 2 col 1 (see LAYOUT) */
keyevent_t encoder2_ccw  = {
    .key = (keypos_t){.row = 4, .col = 0},
    .pressed = false
};

void matrix_scan_user(void) {
    if (IS_PRESSED(encoder_cw)) { /* release enconder CW */
        encoder_cw.pressed = false;
        encoder_cw.time = (timer_read() | 1);
        action_exec(encoder_cw);
    }

    if (IS_PRESSED(encoder_ccw)) { /* release enconder CCW */
        encoder_ccw.pressed = false;
        encoder_ccw.time = (timer_read() | 1);
        action_exec(encoder_ccw);
    }
};

void encoder_update_user(uint8_t index, bool clockwise) {
    // uint8_t layer = get_highest_layer(layer_state);

    if (index == 0) { /* First encoder */
        if (clockwise) {
            encoder_ccw.pressed = true;
            encoder_ccw.time = (timer_read() | 1); /* time should not be 0 */
            action_exec(encoder_ccw);
        } else {
            encoder_cw.pressed = true;
            encoder_cw.time = (timer_read() | 1); /* time should not be 0 */
            action_exec(encoder_cw);
        }
    }
  }
};