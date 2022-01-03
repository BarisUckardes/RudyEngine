#pragma once
namespace Rudy
{
	#define RUDY_KEY_UNKNOWN            -1

		/* Printable keys */
	#define RUDY_KEY_SPACE              32
	#define RUDY_KEY_APOSTROPHE         39  /* ' */
	#define RUDY_KEY_COMMA              44  /* , */
	#define RUDY_KEY_MINUS              45  /* - */
	#define RUDY_KEY_PERIOD             46  /* . */
	#define RUDY_KEY_SLASH              47  /* / */
	#define RUDY_KEY_0                  48
	#define RUDY_KEY_1                  49
	#define RUDY_KEY_2                  50
	#define RUDY_KEY_3                  51
	#define RUDY_KEY_4                  52
	#define RUDY_KEY_5                  53
	#define RUDY_KEY_6                  54
	#define RUDY_KEY_7                  55
	#define RUDY_KEY_8                  56
	#define RUDY_KEY_9                  57
	#define RUDY_KEY_SEMICOLON          59  /* ; */
	#define RUDY_KEY_EQUAL              61  /* = */
	#define RUDY_KEY_A                  65
	#define RUDY_KEY_B                  66
	#define RUDY_KEY_C                  67
	#define RUDY_KEY_D                  68
	#define RUDY_KEY_E                  69
	#define RUDY_KEY_F                  70
	#define RUDY_KEY_G                  71
	#define RUDY_KEY_H                  72
	#define RUDY_KEY_I                  73
	#define RUDY_KEY_J                  74
	#define RUDY_KEY_K                  75
	#define RUDY_KEY_L                  76
	#define RUDY_KEY_M                  77
	#define RUDY_KEY_N                  78
	#define RUDY_KEY_O                  79
	#define RUDY_KEY_P                  80
	#define RUDY_KEY_Q                  81
	#define RUDY_KEY_R                  82
	#define RUDY_KEY_S                  83
	#define RUDY_KEY_T                  84
	#define RUDY_KEY_U                  85
	#define RUDY_KEY_V                  86
	#define RUDY_KEY_W                  87
	#define RUDY_KEY_X                  88
	#define RUDY_KEY_Y                  89
	#define RUDY_KEY_Z                  90
	#define RUDY_KEY_LEFT_BRACKET       91  /* [ */
	#define RUDY_KEY_BACKSLASH          92  /* \ */
	#define RUDY_KEY_RIGHT_BRACKET      93  /* ] */
	#define RUDY_KEY_GRAVE_ACCENT       96  /* ` */
	#define RUDY_KEY_WORLD_1            161 /* non-US #1 */
	#define RUDY_KEY_WORLD_2            162 /* non-US #2 */

	/* Function keys */
	#define RUDY_KEY_ESCAPE             256
	#define RUDY_KEY_ENTER              257
	#define RUDY_KEY_TAB                258
	#define RUDY_KEY_BACKSPACE          259
	#define RUDY_KEY_INSERT             260
	#define RUDY_KEY_DELETE             261
	#define RUDY_KEY_RIGHT              262
	#define RUDY_KEY_LEFT               263
	#define RUDY_KEY_DOWN               264
	#define RUDY_KEY_UP                 265
	#define RUDY_KEY_PAGE_UP            266
	#define RUDY_KEY_PAGE_DOWN          267
	#define RUDY_KEY_HOME               268
	#define RUDY_KEY_END                269
	#define RUDY_KEY_CAPS_LOCK          280
	#define RUDY_KEY_SCROLL_LOCK        281
	#define RUDY_KEY_NUM_LOCK           282
	#define RUDY_KEY_PRINT_SCREEN       283
	#define RUDY_KEY_PAUSE              284
	#define RUDY_KEY_F1                 290
	#define RUDY_KEY_F2                 291
	#define RUDY_KEY_F3                 292
	#define RUDY_KEY_F4                 293
	#define RUDY_KEY_F5                 294
	#define RUDY_KEY_F6                 295
	#define RUDY_KEY_F7                 296
	#define RUDY_KEY_F8                 297
	#define RUDY_KEY_F9                 298
	#define RUDY_KEY_F10                299
	#define RUDY_KEY_F11                300
	#define RUDY_KEY_F12                301
	#define RUDY_KEY_F13                302
	#define RUDY_KEY_F14                303
	#define RUDY_KEY_F15                304
	#define RUDY_KEY_F16                305
	#define RUDY_KEY_F17                306
	#define RUDY_KEY_F18                307
	#define RUDY_KEY_F19                308
	#define RUDY_KEY_F20                309
	#define RUDY_KEY_F21                310
	#define RUDY_KEY_F22                311
	#define RUDY_KEY_F23                312
	#define RUDY_KEY_F24                313
	#define RUDY_KEY_F25                314
	#define RUDY_KEY_KP_0               320
	#define RUDY_KEY_KP_1               321
	#define RUDY_KEY_KP_2               322
	#define RUDY_KEY_KP_3               323
	#define RUDY_KEY_KP_4               324
	#define RUDY_KEY_KP_5               325
	#define RUDY_KEY_KP_6               326
	#define RUDY_KEY_KP_7               327
	#define RUDY_KEY_KP_8               328
	#define RUDY_KEY_KP_9               329
	#define RUDY_KEY_KP_DECIMAL         330
	#define RUDY_KEY_KP_DIVIDE          331
	#define RUDY_KEY_KP_MULTIPLY        332
	#define RUDY_KEY_KP_SUBTRACT        333
	#define RUDY_KEY_KP_ADD             334
	#define RUDY_KEY_KP_ENTER           335
	#define RUDY_KEY_KP_EQUAL           336
	#define RUDY_KEY_LEFT_SHIFT         340
	#define RUDY_KEY_LEFT_CONTROL       341
	#define RUDY_KEY_LEFT_ALT           342
	#define RUDY_KEY_LEFT_SUPER         343
	#define RUDY_KEY_RIGHT_SHIFT        344
	#define RUDY_KEY_RIGHT_CONTROL      345
	#define RUDY_KEY_RIGHT_ALT          346
	#define RUDY_KEY_RIGHT_SUPER        347
	#define RUDY_KEY_MENU               348

	#define RUDY_KEY_LAST               RUDY_KEY_MENU

	#define RUDY_MOUSE_BUTTON_1         0
	#define RUDY_MOUSE_BUTTON_2         1
	#define RUDY_MOUSE_BUTTON_3         2
	#define RUDY_MOUSE_BUTTON_4         3
	#define RUDY_MOUSE_BUTTON_5         4
	#define RUDY_MOUSE_BUTTON_6         5
	#define RUDY_MOUSE_BUTTON_7         6
	#define RUDY_MOUSE_BUTTON_8         7
	#define RUDY_MOUSE_BUTTON_LAST      RUDY_MOUSE_BUTTON_8
	#define RUDY_MOUSE_BUTTON_LEFT      RUDY_MOUSE_BUTTON_1
	#define RUDY_MOUSE_BUTTON_RIGHT     RUDY_MOUSE_BUTTON_2
	#define RUDY_MOUSE_BUTTON_MIDDLE    RUDY_MOUSE_BUTTON_3
}