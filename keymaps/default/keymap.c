/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MEDIA 3
#define _SPECIAL 4

enum unicode_names {
    GRAV,
    TILD,
    LOWL,
    EXCL,
    MAIL, 
    NMBR,
    AMPR,
    ASTR,
    CART,
    PIPE,
    PRCT,
    DLLR,
    LPAR,
    RPAR,
    LSQR,
    RSQR,
    LCUR,
    RCUR,
    LESS,
    MORE,
    PLUS,
    MINS,
    EQLS
};

const uint32_t PROGMEM unicode_map[] = {
    [GRAV]          = 0x0060,   // `
    [TILD]          = 0x007E,   // ~
    [LOWL]          = 0x005F,   // _
    [EXCL]          = 0x0021,   // !
    [MAIL]          = 0x0040,   // @
    [NMBR]          = 0x0023,   // #
    [AMPR]          = 0x0026,   // & 
    [ASTR]          = 0x002A,   // *
    [CART]          = 0x2038,   // ^
    [PIPE]          = 0x007C,   // |
    [PRCT]          = 0x0025,   // %
    [DLLR]          = 0x0024,   // $
    [LPAR]          = 0x0028,   [RPAR]      = 0x0029,   // ( )
    [LSQR]          = 0x005B,   [RSQR]      = 0x005D,   // [ ]
    [LCUR]          = 0x007B,   [RCUR]      = 0x007D,   // { }
    [LESS]          = 0x003C,   [MORE]      = 0x003E,   // < >
    [PLUS]          = 0x002B,   // +
    [MINS]          = 0x002D,   // -
    [EQLS]          = 0x003D,   // =
};



#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// kdefine ONE_GRV LT(1,KC_GRAVE)

// #define CTL_Z LCTL_T(KC_Z)
// #define ALT_SHFT LALT(KC_LSFT)
// #define ALT_MENU LALT_T(KC_MENU)
// #define LG_QUOT LGUI_T(KC_QUOT)
// #define CTL_ESC LCTL_T(KC_ESC)
// #define CTL_SLS LCTL_T(KC_SLSH)
// #define LT2_COL LT(_RAISE, KC_SCLN)

#define L_TAB LT(1, KC_TAB)
#define CTR_ESC LCTL_T(KC_ESC)
#define MDA_PSC LT(3, KC_PSC)
#define L2_BSPC LT(2, KC_BSPC)
#define L4_ENT LT(4, KC_ENT)
/ //Tap Dance Declarations
// enum {
//   TD_ESC_CAPS = 0
// };

// //Tap Dance Definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//   //Tap once for Esc, twice for Caps Lock
//   [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
// // Other declarations would go here, separated by commas, if you have them
// };

// //In Layer declaration, add tap dance item in place of a key code
// TD(TD_ESC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x4(                                  //  BASIC QWERTY LAYER  //
        //
        KC_ESC  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y     , KC_U   ,  KC_I   , KC_O    , KC_P    ,KC_BSLS ,
        //  
        KC_LALT , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H     , KC_J   ,  KC_K   , KC_L    ,LT2_COL  ,KC_QUOT ,
        //
        KC_LSFT , CTL_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,                         KC_N     , KC_M   , KC_COMM , KC_DOT  ,CTL_SLS  ,MDA_PSC ,
        //                                  REPLACE
                                            KC_SPC  , KC_SPC , L_TAB   ,       KC_Y    ,KC_K   , KC_TAB ,
        //                                                     REPLACE
                                            KC_LGUI , CTR_ESC, KC_SPC  ,       KC_Y    ,L2_BSPC , L4_ENT 
    ),
    [_LOWER] = LAYOUT_6x4(                                  // NUMBERS AND F KEYS LAYER //
        _______ ,_______ ,KC_7    ,KC_8    ,KC_9    ,_______ ,                          KC_UP   , KC_F7  , KC_F8  , KC_F9  ,KC_F12  ,KC_F12  ,
        _______ ,KC_0    ,KC_4    ,KC_5    ,KC_6    ,        ,                          KC_DOWN , KC_F4  , KC_F5  , KC_F6  ,KC_F11  ,_______ ,
        _______ ,_______ ,KC_1    ,KC_2    ,KC_3    ,_______ ,                          KC_AMPR , KC_F1  , KC_F2  , KC_F3  ,KC_F10  ,_______ ,
                                            _______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,
                                            _______ ,_______ ,_______ ,        _______ ,_______ ,_______
    ),
    [_RAISE] = LAYOUT_6x4(                                 // MOUSE AND NAVIGATION LAYER //
        _______ ,_______ ,KC_WH_U ,KC_MS_U ,KC_WH_D ,_______ ,                          _______  ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,KC_MS_L ,KC_MS_D ,KC_MS_R ,_______ ,                          _______  ,KC_LEFT ,KC_DOWN , KC_UP  ,KC_RIGHT,_______ ,
        _______ ,_______ ,KC_BTN1 ,KC_BTN3 ,KC_BTN2 ,_______ ,                          _______  ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                            _______ ,_______ ,_______ ,        _______ ,_______  ,_______ ,
                                            _______ ,_______ ,_______ ,        _______ ,_______  ,_______
    ),
    [_MEDIA] = LAYOUT_6x4(                                      // MEDIA KEYS LAYER // 
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ , _______, _______, _______, _______,
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ , _______, _______, _______, _______,
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ , _______, _______, _______, _______,
                                            _______ ,_______ ,_______,         _______ ,_______ ,_______ ,
                                            _______ ,_______ ,_______,         _______ ,_______ ,_______ ,
    ),
    [_SPECIAL] = LAYOUT_6x4(                                 // SPECIAL SYMBOLS LAYER //
        //  `        !        &        |       (         )   
        UM(GRAV),UM(EXCL),UM(AMPR),UM(PIPE),UM(LPAR),UM(RPAR),                          _______, _______, _______, _______, _______, _______,
        //  ~        @        *        %        [        ]
        UM(TILD),UM(MAIL),UM(ASTR),UM(PRCT),UM(LSQR),UM(RSQR),                          _______, _______, _______, _______, _______, _______,
        //  _        #        ^        $        {        }
        UM(LOWL),UM(NMBR),UM(CART),UM(DLLR),UM(LCUR),UM(RCUR),                          _______, _______, _______, _______, _______, _______,
        //                                      <        >
                                            UM(LESS),UM(MORE),_______ ,        _______ ,_______ ,_______ ,
        //
                                            _______ ,_______ ,_______ ,        _______ ,_______ ,_______
    ),
    // [_MEDIA] = LAYOUT_6x4(                                      // MEDIA KEYS LAYER // 
    //     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ , _______, _______, _______, _______,
    //     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ , _______, _______, _______, _______,
    //     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ , _______, _______, _______, _______,
    //                                         _______ ,_______ ,_______,         _______ ,_______ ,_______ ,
    //                                         _______ ,_______ ,_______,         _______ ,_______ ,_______ ,
    // ),
};