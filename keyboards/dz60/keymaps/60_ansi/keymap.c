#include QMK_KEYBOARD_H

#define ______   KC_TRNS

enum custom_keycodes {
    GITPL = SAFE_RANGE,
    GITPS,
	MAGIC,
	LOCK
};

// Note: I use software keyboard transation, so these commands are
// mapped as if I were typing on dvorak on qwerty
// 1 -> git pull
// 2 -> git push
// 3 -> surprise command
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case GITPL:
                SEND_STRING("ugk rfpp"SS_TAP(X_ENTER));
                return false;
            case GITPS:
				SEND_STRING("ugk rf;j"SS_TAP(X_ENTER));
                return false;
			case MAGIC:
				SEND_STRING("gkq; maugi!");
				return false;
			case LOCK:
				SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_DOWN(X_POWER)SS_UP(X_LCTRL)SS_UP(X_LSHIFT)SS_UP(X_POWER));
				return false;
        }
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT_60_ansi(
		KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
		KC_LCTL, KC_LALT,          KC_LGUI,                  KC_SPC,                              MO(1),   KC_UP,            KC_LEFT, KC_RIGHT),

	LAYOUT_60_ansi(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		______,           RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______,  KC_PSCR, KC_SLCK, KC_PAUS, RESET,
		______,           ______,  KC_MRWD, KC_MFFD, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, ______,  KC_INS,  KC_HOME, KC_PGUP, ______,
		______,           GITPL,   GITPS,   MAGIC,   ______,  ______,  ______,  ______,  KC_DEL,  KC_END,  KC_PGDN,          ______,
		LOCK,   ______,             ______,                  ______,                              ______,  KC_DOWN,          KC_HOME, KC_END),
	
	LAYOUT_60_ansi(
		______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,           LOCK,
		______,           ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,
		______,           ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,
		KC_LSFT,          ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,           ______,
		KC_LCTL, ______,           ______,                   ______,                              ______,  ______,           ______,  ______)
};
