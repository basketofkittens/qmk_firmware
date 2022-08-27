#include QMK_KEYBOARD_H

#include "print.h"
#include "wait.h"

// Debug
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

enum keyboard_layers {BASE = 0, FUNC = 1, NUM_LOCK = 2};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐                                   ┌───┬───┬───┐ ┌───┬───┬───┐
     * │Esc│                                   │PSc│Scr│Pse│ │Ins│Hom│PgU│
     * └───┘                                   └───┴───┴───┘ └───┴───┴───┘
     * ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
     * │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │Del│End│PgD│
     * └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘

     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ 
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ 
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ 
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ 
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ 
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┴───┴┬─────────┤ ┌───┼───┼───┐
     * │ Fn │Ctrl│Alt │                        │ Alt     │     Ctrl│ │ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴─────────┴─────────┘ └───┴───┴───┘
     */
     
     // NOTE:   These key mappings are a sparse version of the physical row/col mapping.
     //         They are not ordered per the diagram above. See info.json for the row/col numbering.
     // Base Layer
    [BASE] = LAYOUT_tkl_ansi(
        KC_LSFT,    KC_5,       KC_LCTL,    KC_Y,       KC_7,       KC_U,       KC_6,       KC_J,
        KC_GRV,     KC_Z,       KC_A,       KC_Q,       KC_1,       KC_TAB,     KC_ESC,     KC_F7,
        KC_9,       KC_O,       KC_F8,      KC_L,       KC_DOT,     KC_RWIN,    KC_LALT,    KC_F5,
        KC_BSPC,    KC_F10,     KC_F9,      KC_BSLS,    KC_ENT,     KC_PSCR,    KC_SCRL,    KC_SPC,
        KC_PGDN,    KC_PGUP,    KC_LEFT,    KC_UP,      KC_END,     KC_HOME,    KC_PAUS,    KC_F1,
        KC_X,       KC_S,       MO(FUNC),   KC_W,       KC_2,       KC_CAPS,    KC_RCTL,    KC_F2,
        KC_C,       KC_D,       KC_E,       KC_3,       KC_F3,      KC_F4,      KC_SLSH,    KC_QUOT,
        KC_LBRC,    KC_0,       KC_P,       KC_MINS,    KC_SCLN,    KC_M,       KC_N,       KC_H,
        KC_RGHT,    KC_F12,     KC_INS,     KC_V,       KC_F,       KC_B,       KC_R,       KC_4,
        KC_T,       KC_G,       KC_DOWN,    KC_F11,     KC_DEL,     KC_F6,      KC_RBRC,    KC_8,
        KC_I,       KC_EQL,     KC_K,       KC_COMM,    KC_RSFT
    ),

     // Function Key Layer
    [FUNC] = LAYOUT_tkl_ansi(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_LWIN,        KC_MUTE,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      TG(NUM_LOCK),   KC_NO,
        KC_VOLD,    KC_VOLU,    KC_NO,      KC_NO,      KC_BRID,    KC_BRIU,    KC_NO,          KC_NO,
        KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,
        KC_NO,      KC_NO,      KC_INS,     KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO
    ),

     // Num Lock Layer
    [NUM_LOCK] = LAYOUT_tkl_ansi(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_7,       KC_4,       KC_NO,      KC_1,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_9,       KC_6,       KC_NO,      KC_3,       KC_DOT,     KC_NO,      KC_NO,      KC_NO,
        KC_BSPC,    KC_NO,      KC_NO,      KC_NO,      KC_ENT,     KC_NO,      KC_TRNS,    KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_PPLS,    KC_NO,
        KC_NO,      KC_PSLS,    KC_PAST,    KC_NO,      KC_PMNS,    KC_0,       KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_8,
        KC_5,       KC_NO,      KC_2,       KC_NO,      KC_NO
    )
};