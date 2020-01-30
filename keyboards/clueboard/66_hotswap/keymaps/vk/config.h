#pragma once


#ifdef AUDIO_ENABLE
#   define AUDIO_CLICKY
#   define STARTUP_SONG SONG(SONIC_RING)
#   define GOODBYE_SONG  SONG(SONIC_RING)
#   define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                    SONG(COLEMAK_SOUND), \
                                    SONG(DVORAK_SOUND), \
                                    SONG(OVERWATCH_THEME) \
                                }
#	define AUDIO_CLICKY
#	define AUDIO_CLICKY_FREQ_DEFAULT 440.0f
#	define AUDIO_CLICKY_FREQ_MIN 65.0f
#	define AUDIO_CLICKY_FREQ_MAX 1500.0f
#	define AUDIO_CLICKY_FREQ_FACTOR 1.18921f
//#	define AUDIO_CLICKY_FREQ_FACTOR 2.71828f  // e
//#	define AUDIO_CLICKY_FREQ_FACTOR 1.61803f // golden ratio
#	define AUDIO_CLICKY_FREQ_RANDOMNESS 0.05f
#endif // !AUDIO_ENABLE

#define GRAVE_ESC_SHIFT_OVERRIDE

/*#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_SLEEP
#   undef RGBLIGHT_ANIMATIONS
#   define RGBLIGHT_EFFECT_BREATHING
#   define RGBLIGHT_EFFECT_SNAKE
#   define RGBLIGHT_EFFECT_KNIGHT
#	define RGBLIGHT_MODE_STATIC_LIGHT
#endif // RGBLIGHT_ENABLE*/

#undef NO_ACTION_TAPPING