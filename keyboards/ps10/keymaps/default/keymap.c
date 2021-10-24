/* Copyright 2021 KomischerName
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
// #include "print.h"

#define _BASE 0
#define _KEYPAD 1
#define _LOGIC 2
#define _ARROWS 3
#define _MEMES 4

#define KC_QUAK LGUI(LALT(KC_BSLS))
#define VC_MUTE LALT(KC_M)
#define VC_VIDM LALT(KC_V)

enum custom_keycodes {
    SHRUG = 1024,
    FLIP,
    ACID,
    ANGRY,
    FIGHT,
    STALK,
    YOLO
};

int DEFAULT_SAT = 0xFF;
int DEFAULT_VAL = 0x10;

int BASE_COLOUR = 0;
int KEYPAD_COLOUR = 180;
int LOGIC_COLOUR = 127;
int ARROWS_COLOUR = 64;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    int val = rgblight_get_val();

    switch (keycode) {
        case SHRUG:
            if (record->event.pressed) {
              if (get_mods() & MOD_MASK_CSA) {
                layer_move(_BASE);
                rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                rgblight_sethsv(BASE_COLOUR, DEFAULT_SAT, val);
              } else {
                tap_code(KC_F17);
                wait_ms(100);
                send_unicode_string("¯\\_(ツ)_/¯");
                tap_code(KC_F17);
              }
            }
            return false;
            break;
        case FLIP:
            if (record->event.pressed) {
              if (get_mods() & MOD_MASK_CSA) {
                layer_move(_KEYPAD);
                rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                rgblight_sethsv(KEYPAD_COLOUR, DEFAULT_SAT, val);
              } else {
                tap_code(KC_F17);
                wait_ms(100);
                send_unicode_string("(ノಠ益ಠ)ノ彡┻━┻");
                tap_code(KC_F17);
              }
            }
            return false;
            break;
        case ACID:
            if (record->event.pressed) {
              if (get_mods() & MOD_MASK_CSA) {
                layer_move(_LOGIC);
                rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                rgblight_sethsv(LOGIC_COLOUR, DEFAULT_SAT, val);
              } else {
                tap_code(KC_F17);
                wait_ms(100);
                send_unicode_string("⊂(◉‿◉)つ");
                tap_code(KC_F17);
              }
            }
            return false;
            break;
        case ANGRY:
            if (record->event.pressed) {
              if (get_mods() & MOD_MASK_CSA) {
                layer_move(_ARROWS);
                rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                rgblight_sethsv(ARROWS_COLOUR, DEFAULT_SAT, val);
              } else {
                tap_code(KC_F17);
                wait_ms(100);
                send_unicode_string("•`_´•");
                tap_code(KC_F17);
              }
            }
            return false;
            break;
        case FIGHT:
            if (record->event.pressed) {
              tap_code(KC_F17);
              wait_ms(100);
              send_unicode_string("(ง •̀_•́)ง");
              tap_code(KC_F17);
            }
            return false;
            break;
        case STALK:
            if (record->event.pressed) {
              tap_code(KC_F17);
              wait_ms(100);
              send_unicode_string("┬┴┬┴┤(･_├┬┴┬┴");
              tap_code(KC_F17);
            }
            return false;
            break;
        case YOLO:
            if (record->event.pressed) {
              tap_code(KC_F17);
              wait_ms(100);
              send_unicode_string("Yᵒᵘ Oᶰˡʸ Lᶤᵛᵉ Oᶰᶜᵉ");
              tap_code(KC_F17);
            }
            return false;
            break;
        case VC_MUTE:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_KEYPAD);
            rgblight_sethsv(KEYPAD_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
        case VC_VIDM:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_LOGIC);
            rgblight_sethsv(LOGIC_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
          break;
        case KC_F16:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_ARROWS);
            rgblight_sethsv(ARROWS_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
          break;
        case KC_F17:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_MEMES);
            // rgblight_sethsv(MEMES_COLOUR, DEFAULT_SAT, val);
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
            return false;
          }
          return true;
          break;
        case KC_P1:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_BASE);
            rgblight_sethsv(BASE_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
          break;
        case KC_P3:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_LOGIC);
            rgblight_sethsv(LOGIC_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
          break;
        case KC_P4:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_ARROWS);
            rgblight_sethsv(ARROWS_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
          break;
        case KC_P5:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_MEMES);
            // rgblight_sethsv(MEMES_COLOUR, DEFAULT_SAT, val);
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
            return false;
          }
          return true;
          break;
        case KC_SPC:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_BASE);
            rgblight_sethsv(BASE_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
          break;
        case KC_ENT:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_KEYPAD);
            rgblight_sethsv(KEYPAD_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
          break;
        case KC_COMM:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_ARROWS);
            rgblight_sethsv(ARROWS_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
          break;
        case KC_C:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_MEMES);
            // rgblight_sethsv(MEMES_COLOUR, DEFAULT_SAT, val);
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
            return false;
          }
          return true;
          break;
        case KC_END:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_BASE);
            rgblight_sethsv(BASE_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
          break;
        case KC_DOWN:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_KEYPAD);
            rgblight_sethsv(KEYPAD_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
          break;
        case KC_PGDN:
          if ((get_mods() & MOD_MASK_CSA) && record->event.pressed) {
            layer_move(_LOGIC);
            rgblight_sethsv(LOGIC_COLOUR, DEFAULT_SAT, val);
            return false;
          }
          return true;
          break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE LAYER
    /-----------------------------`
    |   Vol-  |   Mute  |  Vol+   |
    |         |---------|         |
    |---------|         |---------|
    |                   | RGB_TOG |
    |---------|---------|---------|
    |   F13   |   F14   |   F15   |
    |---------|---------|---------|
    |   F16   |   F17   |   F18   |
    |---------|---------|---------|
    |   F19   |   F20   |   F21   |
    \-----------------------------'
    */
    [_BASE] = LAYOUT(
                        RGB_TOG,
                                        KC_MEH,
        KC_NO,          KC_NO,          KC_NO,
     // mono toggle     input toggle
        KC_F16,         KC_F17,         KC_NO,
     //                 vc mute
        KC_QUAK,        VC_MUTE,        VC_VIDM
    ),
    [_KEYPAD] = LAYOUT(
                        RGB_TOG,
                                        MEH_T(KC_P0),
        KC_P7,          KC_P8,          KC_P9,
        KC_P4,          KC_P5,          KC_P6,
        KC_P1,          KC_P2,          KC_P3
    ),
    [_LOGIC] = LAYOUT(
                        RGB_TOG,
                                        KC_MEH,
        KC_M,           KC_S,           KC_E,
        KC_COMMA,       KC_C,           KC_DOT,
        KC_SPC,         KC_ENT,         KC_DEL
    ),
    [_ARROWS] = LAYOUT(
                        RGB_TOG,
                                        KC_MEH,
        KC_HOME,        KC_UP,          KC_PGUP,
    //                  input toggle, for layer switching
        KC_LEFT,        KC_F17,         KC_RIGHT,
        KC_END,         KC_DOWN,        KC_PGDN
    ),
    [_MEMES] = LAYOUT(
                        RGB_TOG,
                                        KC_MEH,
        YOLO,           KC_NO,          KC_NO,
        ANGRY,          FIGHT,          STALK,
        SHRUG,          FLIP,           ACID
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {
        case 0:
            if (get_mods() & MOD_MASK_CSA) {
              uint8_t mod_state = get_mods();
              del_mods(mod_state);
              if (clockwise) {
                rgblight_decrease_val();
              } else {
                rgblight_increase_val();
              }
              set_mods(mod_state);
            } else {
              if (clockwise) {
                  register_code(KC_LGUI);
                  tap_code(KC_Z);
                  unregister_code(KC_LGUI);
              } else {
                  register_code(KC_LGUI);
                  register_code(KC_LSFT);
                  tap_code(KC_Z);
                  unregister_code(KC_LSFT);
                  unregister_code(KC_LGUI);
              }
              break;
            }
        default:
            if (get_mods() & MOD_MASK_CSA) {
              uint8_t mod_state = get_mods();
              del_mods(mod_state);
              if (clockwise) {
                rgblight_decrease_val();
              } else {
                rgblight_increase_val();
              }
              set_mods(mod_state);
            } else {
              if (clockwise) {
                  tap_code(KC_MS_WH_DOWN);
              } else {
                  tap_code(KC_MS_WH_UP);
              }
            }
    }
    return true;
}

void keyboard_post_init_user(void) {
  rgblight_sethsv(BASE_COLOUR, DEFAULT_SAT, DEFAULT_VAL);
}
