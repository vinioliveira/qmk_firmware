#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _VIM,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  VIM,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Vim  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  | Vim  |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_planck_mit(
      KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,      KC_BSPC,
      KC_CAPSLOCK, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,   KC_ENT,
      KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   KC_RSHIFT,
      VIM,         KC_LCTL, KC_LALT, KC_LGUI, LOWER,       KC_SPC,       RAISE,   KC_RGUI, KC_RCTRL, LGUI(LSFT(KC_4)), VIM
      ),

  /* Colemk
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Vim  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  | Vim  |
   * `-----------------------------------------------------------------------------------'
   */
  [_COLEMAK] = LAYOUT_planck_mit(
      KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,      KC_BSPC,
      KC_CAPSLOCK, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,   KC_ENT,
      KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   KC_RSHIFT,
      VIM,         KC_LCTL, KC_LALT, KC_LGUI, LOWER,       KC_SPC,       RAISE,   KC_RGUI, KC_RCTRL, LGUI(LSFT(KC_4)), VIM
      ),

  /* Vim
   * ,-----------------------------------------------------------------------------------.
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   ^  |   (  |   )  |   [  |   ]  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |   =  | Left | Down |  Up  |Right |  \   |  |   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |  -   |  *   |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_VIM] = LAYOUT_planck_mit(
      KC_GRAVE, KC_EXCLAIM, KC_AT  , KC_HASH, KC_DLR , KC_PERC , KC_CIRC      , KC_LPRN    , KC_RPRN, KC_LBRACKET, KC_RBRACKET, KC_BSPACE,
      _______ , _______   , _______, _______, _______, KC_EQUAL, KC_LEFT      , KC_DOWN    , KC_UP  , KC_RIGHT   , KC_BSLASH  , KC_PIPE,
      _______ , _______   , _______, _______, _______, _______ , KC_MINUS     , KC_ASTERISK, _______, _______    , _______    , _______,
      _______ , _______   , _______, _______, _______,          _______       , _______    , _______, _______    , _______    , _______
      ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |      |  1   |  2   |  3   |  4   |  5   |   6  |   7  |   8  |  9   |  0   |   "  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      | Play | Next | Prev |Vol + |Vol - |      |   4  |   5  |  6   |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |A+G+F |A+G+< |A+G+> |A+C+< |A+C+> |      |   1  |  2   |  3   |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | CTRL | ALT  |  GUI |      |             |   ,  |  0   |  .   |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_mit(
      _______ , KC_1             , KC_2             , KC_3              , KC_4             , KC_5              ,KC_6  , KC_7  , KC_8 , KC_9 , KC_0 , KC_QUOTE,
      _______ , KC_MEDIA_PLAY_PAUSE , KC_MEDIA_NEXT_TRACK , KC_MEDIA_PREV_TRACK  , KC_AUDIO_VOL_UP     , KC_AUDIO_VOL_DOWN    , _______ , KC_4  , KC_5 , KC_6 , _______ , _______ ,
      _______ , LALT(RGUI(KC_F))    , LALT(RGUI(KC_LEFT)) , LALT(RGUI(KC_RIGHT)) , LALT(LCTL(KC_LEFT)) , LALT(LCTL(KC_RIGHT)) , _______ , KC_1  , KC_2 , KC_3 , _______ , _______ ,
      _______ , KC_RCTRL            , KC_RALT             , KC_RGUI              , _______             ,           _______              , KC_COMMA , KC_0 , KC_DOT  , _______ , _______
      ),


  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   ^  |   (  |   )  |   [  |   ]  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |CTRL+1|CTRL+2|CTRL+3|CTRL+4|CTRL+5|CTRL+6|CTRL+7|CTRL+8|CTRL+9|CTRL+0|      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_planck_mit(
      LSFT(KC_GRAVE) , KC_EXCLAIM , KC_AT      , KC_HASH    , KC_DLR     , KC_PERC    , KC_CIRC    , KC_LPRN    , KC_RPRN    , KC_LBRACKET , KC_RBRACKET , KC_BSPACE ,
      LCTL(KC_1)     , LCTL(KC_2) , LCTL(KC_3) , LCTL(KC_4) , LCTL(KC_5) , LCTL(KC_6) , LCTL(KC_7) , LCTL(KC_8) , LCTL(KC_9) , LCTL(KC_0)  , _______     , _______   ,
      _______        , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______     , _______     , _______   ,
      _______        , _______    , _______    , _______    , _______    ,        _______          , _______    , _______    , _______     , _______     , _______
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |      |      |      |      |  Del |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |AGnorm|AGswap|Qwerty|Colemk|      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_planck_mit(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL ,
      _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
      )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case VIM:
      if (record->event.pressed) {
        layer_on(_VIM);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_VIM);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
