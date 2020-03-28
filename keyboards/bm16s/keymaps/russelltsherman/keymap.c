#include QMK_KEYBOARD_H

enum custom_keycodes {
    OP_CHROME = SAFE_RANGE,
    OP_NOTES,
    OP_TERM,
    OP_VSCODE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case OP_CHROME:
                SEND_STRING(SS_DOWN(X_LGUI));
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING(SS_UP(X_LGUI));
                SEND_STRING(SS_DELAY(100));
                SEND_STRING("Chrome");
                SEND_STRING(SS_TAP(X_ENTER));
                return false;break;
            case OP_NOTES:
                SEND_STRING(SS_DOWN(X_LGUI));
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING(SS_UP(X_LGUI));
                SEND_STRING(SS_DELAY(100));
                SEND_STRING("Joplin");
                SEND_STRING(SS_TAP(X_ENTER));
                return false;break;
            case OP_TERM:
                SEND_STRING(SS_DOWN(X_LGUI));
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING(SS_UP(X_LGUI));
                SEND_STRING(SS_DELAY(100));
                SEND_STRING("Terminal");
                SEND_STRING(SS_TAP(X_ENTER));
                return false;break;
            case OP_VSCODE:
                SEND_STRING(SS_DOWN(X_LGUI));
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING(SS_UP(X_LGUI));
                SEND_STRING(SS_DELAY(100));
                SEND_STRING("Visual Studio Code");
                SEND_STRING(SS_TAP(X_ENTER));
                return false;break;
        }
    }
    return true;
};

enum layers {
  _BASE = 0,
  _FN1,
  _FN2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /**
     * .-------------------.
     * | OP_TERM   |   |   | Fn |
     * | OP_VSCODE |   |   |    |
     * | OP_CHROME |   |   |    |
     * | OP_NOTES  |   |   |    |
     * .-------------------.
     */
	[_BASE] = LAYOUT_ortho_4x4(
		OP_TERM, _______, _______, MO(_FN1), \
		OP_VSCODE, _______, _______, _______, \
		OP_CHROME, _______, _______, _______, \
		OP_NOTES, _______, _______, _______  \
	),

    /**
     * .---------------------------------------.
     * | RESET   | BL_STEP |         | KC_VOLU |
     * | BL_TOGG | BL_DEC  | BL_INC  | KC_VOLD |
     * | RGB_TOG | RGB_MOD | RGB_HUI | KC_MUTE |
     * | RGB_SAI | RGB_SAD | RGB_HUD |         |
     * .---------------------------------------.
     */
	[_FN1] = LAYOUT_ortho_4x4(
		RESET,   BL_STEP, _______, KC_VOLU, \
		BL_TOGG, BL_DEC,  BL_INC,  KC_VOLD, \
		RGB_TOG, RGB_MOD, RGB_HUI, KC_MUTE, \
		RGB_SAI, RGB_SAD, RGB_HUD, _______  \
	),

    /**
     * .-------------------.
     * | 7 | 8 | 9 | Fn    |
     * | 4 | 5 | 6 | -     |
     * | 1 | 2 | 3 | +     |
     * | 0 | . | , | Enter |
     * .-------------------.
     */
	[_FN2] = LAYOUT_ortho_4x4(
		KC_KP_7, KC_KP_8, KC_KP_9, MO(_FN1), \
		KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, \
		KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, \
		KC_KP_0, KC_PDOT, KC_PCMM, KC_PENT  \
	),

};

// Backlighting
// BL_TOGG	Turn the backlight on or off
// BL_STEP	Cycle through backlight levels
// BL_ON	Set the backlight to max brightness
// BL_OFF	Turn the backlight off
// BL_INC	Increase the backlight level
// BL_DEC	Decrease the backlight level
// BL_BRTG	Toggle backlight breathing

// KC_VOLU	Volume Up
// KC_VOLD	Volume Down
// KC_MUTE	Mute

// RGB_TOG Toggle RGB lighting on or off
// RGB_MOD Cycle through modes, reverse direction when Shift is held
// RGB_HUI Increase hue, decrease hue when Shift is held
// RGB_SAI Increase saturation, decrease saturation when Shift is held
// RGB_SAD Decrease saturation, increase saturation when Shift is held
// RGB_HUD Decrease hue, increase hue when Shift is held

// SS_TAP() presses and releases a key.
// SS_DOWN() presses (but does not release) a key.
// SS_UP() releases a key.

// SS_LCTL(string)
// SS_LSFT(string)
// SS_LALT(string)
// SS_LGUI(string), SS_LCMD(string) or SS_LWIN(string)
// SS_RCTL(string)
// SS_RSFT(string)
// SS_RALT(string) or SS_ALGR(string)
// SS_RGUI(string), SS_RCMD(string) or SS_RWIN(string)
