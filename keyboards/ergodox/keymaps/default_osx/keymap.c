// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|  LGui  |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
	// left hand
		KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_ESC,
		KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_BSLS,
		KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
		KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_FN1,
		KC_QUOT,        KC_EQL,       KC_LCTL,  KC_LALT,   KC_LGUI,
		KC_LCTL,   KC_LALT,
		KC_HOME,
		KC_BSPC, KC_DEL, KC_END,

	// right hand
		KC_EQL,   KC_6,    KC_7,   KC_8,    KC_9,   KC_0,      KC_MINS,
		KC_RBRC,  KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,      KC_LBRC,
			  KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN,   KC_RCTL,
		KC_FN1,   KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_RSFT,
		KC_LEFT,  KC_DOWN, KC_UP,  KC_RGHT, KC_RGUI,
		KC_RALT,  KC_RCTL,
		KC_PGUP,
		KC_PGDN,  KC_ENT, KC_SPC

    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
       KC_F14,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_F15,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_FN3,  KC_FN4,  KC_FN5,  KC_FN6,  KC_FN7,  KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

				       KC_TRNS,KC_TRNS,
					       KC_TRNS,
			       KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY,
			 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

};

enum macro_id {
  PASSWORD1,
  PASSWORD2,
  PASSWORD3,
  PASSWORD4,
  PASSWORD5,
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_MOMENTARY(1),             // FN1 - Momentary Layer 1
  [2] = ACTION_LAYER_SET(0, ON_PRESS),         // FN2 - set Layer 0
  [3] = ACTION_MACRO(PASSWORD1),
  [4] = ACTION_MACRO(PASSWORD2),
  [4] = ACTION_MACRO(PASSWORD3),
  [5] = ACTION_MACRO(PASSWORD4),
  [6] = ACTION_MACRO(PASSWORD5),
};

#include "keymap_passwords.h"

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  if (record->event.pressed) {
    switch(id) {
    case PASSWORD1:  return MACRO_PASSWORD1;
    case PASSWORD2:  return MACRO_PASSWORD2;
    case PASSWORD3:  return MACRO_PASSWORD3;
    case PASSWORD4:  return MACRO_PASSWORD4;
    case PASSWORD5:  return MACRO_PASSWORD5;
    }
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
	case 1:
	    ergodox_right_led_1_on();
	    break;
	case 2:
	    ergodox_right_led_2_on();
	    break;
	default:
	    // none
	    break;
    }

};
