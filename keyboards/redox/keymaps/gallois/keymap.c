#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */
#define _QWERTY 0
#define _QWERTY_PC 1
#define _FN_NAV 2
#define _SYM 3
#define _MOUSE_MEDIA 4


enum custom_keycodes {
    MACCY = SAFE_RANGE,
    CONTEXTS,
    ITERM,
};

#define KC_SYUP LT(_SYM, KC_PGUP)
#define KC_FNDN LT(_FN_NAV, KC_PGDN)
#define KC_FNHM LT(_FN_NAV, KC_HOME) 
#define KC_SEND LT(_SYM, KC_END)
#define KC_MM   TT(_MOUSE_MEDIA)
#define KC_SGES LSG_T(KC_ESC)
#define KC_CSES C_S_T(KC_ESC)
#define KC_TQPC TG(_QWERTY_PC)
#define KC_TFNN TG(_FN_NAV)
#define KC_TSYM TG(_SYM)
#define KC_TMM  TG(_MOUSE_MEDIA)
#define KC_ASL  LALT(LSFT(KC_LEFT))
#define KC_ASD  LALT(LSFT(KC_DOWN))
#define KC_ASU  LALT(LSFT(KC_UP))
#define KC_ASR  LALT(LSFT(KC_RGHT))
#define KC_SFTL LSFT(KC_LEFT)
#define KC_SFTD LSFT(KC_DOWN)
#define KC_SFTU LSFT(KC_UP)
#define KC_SFTR LSFT(KC_RGHT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case MACCY:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) SS_TAP(X_V) SS_UP(X_LGUI) SS_UP(X_LSFT));
            }
            return false;
            break;
        case CONTEXTS:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) SS_TAP(X_SPACE) SS_UP(X_LGUI) SS_UP(X_LSFT));
            }
            return false;
            break;
        case ITERM:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_BSLS) SS_UP(X_LGUI) SS_UP(X_LALT));
            }
            return false;
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_LPRN ,                          KC_RPRN ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_SYUP ,KC_FNDN ,        KC_FNHM ,KC_SEND ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_MM   ,KC_CAPS ,MACCY   ,KC_LALT ,     KC_LGUI ,    KC_BSPC ,KC_SGES ,        KC_ENT  ,KC_SPC  ,    KC_RGUI ,     KC_RALT ,CONTEXTS,KC_EQL  ,KC_MM
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
    [_QWERTY_PC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_LPRN ,                          KC_RPRN ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_SYUP ,KC_FNDN ,        KC_FNHM ,KC_SEND ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_MM   ,KC_CAPS ,KC_NO   ,KC_LGUI ,     KC_LALT ,    KC_BSPC ,KC_CSES ,        KC_ENT  ,KC_SPC  ,    KC_RALT ,     KC_RGUI ,KC_NO   ,KC_EQL  ,KC_MM
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
   ),
    [_FN_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO   ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_NO   ,KC_UP   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_F11  ,                          KC_F12  ,KC_ASL  ,KC_ASD  ,KC_ASU  ,KC_ASR  ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_NO   ,KC_NO   ,KC_HOME ,                          KC_END  ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_TRNS ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,KC_SFTL ,KC_SFTD ,KC_SFTU ,KC_SFTR ,KC_NO   ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_NO   ,KC_NO   ,KC_TRNS ,     KC_TRNS ,    KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,    KC_TRNS ,     KC_TRNS ,KC_NO   ,KC_NO   ,KC_TRNS
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
    [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO   ,KC_TQPC ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,                                            KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_PGDN ,KC_NO   ,                          KC_NO   ,KC_PGUP ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,KC_LPRN ,                          KC_RPRN ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,ITERM   ,KC_TRNS ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,ITERM   ,KC_PPLS ,KC_PEQL ,KC_UNDS ,KC_PMNS ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_NO   ,KC_NO   ,KC_TRNS ,     KC_TRNS ,    KC_DEL  ,KC_NO   ,        KC_NO   ,KC_NO   ,    KC_TRNS ,     KC_TRNS ,KC_NO   ,KC_NO   ,KC_TRNS
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
    [_MOUSE_MEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO   ,RGB_TOG ,RGB_MOD ,RGB_HUI ,RGB_HUD ,RGB_M_P ,                                            KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_BTN1 ,KC_MS_U ,KC_BTN2 ,KC_WH_U ,KC_NO   ,KC_NO   ,                          KC_NO   ,KC_NO   ,KC_VOLD ,KC_VOLU ,KC_MUTE ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,KC_NO   ,KC_NO   ,                          KC_NO   ,KC_NO   ,KC_MRWD ,KC_MPLY ,KC_MFFD ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,KC_NO   ,KC_NO   ,KC_TRNS ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_NO   ,KC_NO   ,KC_TRNS ,     KC_TRNS ,    KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,    KC_TRNS ,     KC_TRNS ,KC_NO   ,KC_NO   ,KC_TRNS
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
};
