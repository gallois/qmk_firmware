#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _QWERTY_PC 1
#define _GAME 2
#define _FN_NAV 3
#define _SYM 4
#define _MOUSE_MEDIA 5
#define _NUM_KEY 6

#define KC_SYUP LT(_SYM, KC_PGUP)
#define KC_FNDN LT(_FN_NAV, KC_PGDN)
#define KC_FNHM LT(_FN_NAV, KC_HOME)
#define KC_SEND LT(_SYM, KC_END)
#define KC_NCAP LT(_NUM_KEY, KC_CAPS)
#define KC_MM   TT(_MOUSE_MEDIA)
#define KC_FF   TT(_FN_NAV)
#define KC_SGES LSG_T(KC_ESC)
#define KC_AGNO LAG_T(KC_NO)
#define KC_CANO LCA_T(KC_NO)
#define KC_CSES C_S_T(KC_ESC)
#define KC_TQPC TG(_QWERTY_PC)
#define KC_TGAM TG(_GAME)
#define KC_TFNN TG(_FN_NAV)
#define KC_TSYM TG(_SYM)
#define KC_TMM  TG(_MOUSE_MEDIA)
#define KC_SFTL LSFT(KC_LEFT)
#define KC_SFTD LSFT(KC_DOWN)
#define KC_SFTU LSFT(KC_UP)
#define KC_SFTR LSFT(KC_RIGHT)
#define KC_ASL  LALT(LSFT(KC_LEFT))
#define KC_ASD  LALT(LSFT(KC_DOWN))
#define KC_ASU  LALT(LSFT(KC_UP))
#define KC_ASR  LALT(LSFT(KC_RIGHT))
#define KC_MTL  LSFT(LGUI(KC_LBRC))
#define KC_MTR  LSFT(LGUI(KC_RBRC))

enum {
    TD_L_BRAC = 0,
    TD_R_BRAC,
    TD_LP_PPLS,
    TD_RP_PEQL,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_L_BRAC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_R_BRAC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TD_LP_PPLS] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_PPLS),
    [TD_RP_PEQL] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_PEQL),
};

#define KC_TDLB TD(TD_L_BRAC)
#define KC_TDRB TD(TD_R_BRAC)
#define KC_LPPL TD(TD_LP_PPLS)
#define KC_RPEQ TD(TD_RP_PEQL)

const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_OFF}
);
const rgblight_segment_t PROGMEM qwerty_pc_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_OFF}
);
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_RED}
);
const rgblight_segment_t PROGMEM game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM fn_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_AZURE}
);
const rgblight_segment_t PROGMEM mouse_media_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_SPRINGGREEN}
);
const rgblight_segment_t PROGMEM num_key_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_YELLOW}
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_LPPL ,                          KC_RPEQ ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_TDLB ,                          KC_TDRB ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_SYUP ,KC_FNDN ,        KC_FNHM ,KC_SEND ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_MM   ,KC_NCAP ,KC_AGNO ,KC_LALT ,     KC_LGUI ,    KC_BSPC ,KC_SGES ,        KC_ENT  ,KC_SPC  ,    KC_RGUI ,     KC_RALT ,KC_AGNO ,KC_CANO ,KC_FF
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
    [_QWERTY_PC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_LPPL ,                          KC_RPEQ ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_TDLB ,                          KC_TDRB ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_SYUP ,KC_FNDN ,        KC_FNHM ,KC_SEND ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_MM   ,KC_NCAP ,KC_CANO ,KC_LGUI ,     KC_LALT ,    KC_BSPC ,KC_CSES ,        KC_ENT  ,KC_SPC  ,    KC_RALT ,     KC_RGUI ,KC_CANO ,KC_CANO ,KC_FF
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
    [_GAME] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_LPPL ,                          KC_RPEQ ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_TDLB ,                          KC_TDRB ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_SYUP ,KC_FNDN ,        KC_FNHM ,KC_SEND ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_BSPC ,KC_CANO ,KC_LGUI ,     KC_LALT ,    KC_SPC  ,KC_ENT  ,        KC_ENT  ,KC_SPC  ,    KC_RALT ,     KC_RGUI ,KC_CANO ,KC_CANO ,KC_FF
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
     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,     KC_TRNS ,    KC_TRNS ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,    KC_TRNS ,     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
    [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO   ,KC_TQPC ,KC_TGAM ,KC_NO   ,KC_NO   ,KC_NO   ,                                            KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_PGDN ,KC_NO   ,                          KC_NO   ,KC_PGUP ,KC_MTL  ,KC_MTR  ,KC_NO   ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,KC_LPRN ,                          KC_RPRN ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_TRNS ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,KC_NO   ,KC_PPLS ,KC_PEQL ,KC_UNDS ,KC_PMNS ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,     KC_TRNS ,    KC_DEL  ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,    KC_TRNS ,     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
    [_MOUSE_MEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,                                            KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_BTN1 ,KC_MS_U ,KC_BTN2 ,KC_WH_U ,KC_NO   ,KC_NO   ,                          KC_NO   ,KC_NO   ,KC_VOLD ,KC_VOLU ,KC_MUTE ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,KC_NO   ,KC_NO   ,                          KC_NO   ,KC_NO   ,KC_MRWD ,KC_MPLY ,KC_MFFD ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,KC_NO   ,KC_NO   ,KC_TRNS ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,     KC_TRNS ,    KC_TRNS ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,    KC_TRNS ,     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
    [_NUM_KEY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,                                            KC_NO   ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PSLS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,                          KC_NO   ,KC_NO   ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PAST ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,                          KC_NO   ,KC_NO   ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PMNS ,KC_PENT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO ,  KC_NO   ,KC_PCMM ,KC_P0   ,KC_PDOT ,KC_PPLS ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,     KC_TRNS ,    KC_TRNS ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,    KC_TRNS ,     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
};

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    qwerty_pc_layer,
    capslock_layer,
    game_layer,
    fn_nav_layer,
    sym_layer,
    mouse_media_layer,
    num_key_layer,
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(2, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY_PC));
    rgblight_set_layer_state(3, layer_state_cmp(state, _GAME));
    rgblight_set_layer_state(4, layer_state_cmp(state, _FN_NAV));
    rgblight_set_layer_state(5, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(6, layer_state_cmp(state, _MOUSE_MEDIA));
    rgblight_set_layer_state(7, layer_state_cmp(state, _NUM_KEY));
    return state;
}
