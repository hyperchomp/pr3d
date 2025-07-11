#ifndef PR3D_INPUT_H
#define PR3D_INPUT_H

#include <stdbool.h>
#include <GLFW/glfw3.h>

bool pr3d_key_pressed(int key);

/**
 * Gets the mouse cursor x,y positions and stores them in x_pos and y_pos.
 *
 * Will return a screen position with 0,0 in the upper left if mouse capture
 * mode is PR3D_MOUSE_CAPTURED, or an unbounded double if capture mode is
 * PR3D_MOUSE_DISABLED.
 *
 * @param x_pos
 * @param y_pos
 */
void pr3d_mouse_position(double *x_pos, double *y_pos);

/**
 * KEYCODE MAPPINGS
 * These are solely for the purpose of mapping to GLFW keycodes to abstract
 * out GLFW so it does not need to be included in a project.
 *
 * This also means the printable keys map to 7-bit ASCII, and the mappings
 * follow a US keyboard layout
 */
enum PR3DKeyboardKey
{
    /* Printable keys */
    PR3D_KEY_SPACE = GLFW_KEY_SPACE,
    PR3D_KEY_APOSTROPHE = GLFW_KEY_APOSTROPHE, /* ' */
    PR3D_KEY_COMMA = GLFW_KEY_COMMA,           /* , */
    PR3D_KEY_MINUS = GLFW_KEY_MINUS,           /* - */
    PR3D_KEY_PERIOD = GLFW_KEY_PERIOD,         /* . */
    PR3D_KEY_SLASH = GLFW_KEY_SLASH,           /* / */
    PR3D_KEY_0 = GLFW_KEY_0,
    PR3D_KEY_1 = GLFW_KEY_1,
    PR3D_KEY_2 = GLFW_KEY_2,
    PR3D_KEY_3 = GLFW_KEY_3,
    PR3D_KEY_4 = GLFW_KEY_4,
    PR3D_KEY_5 = GLFW_KEY_5,
    PR3D_KEY_6 = GLFW_KEY_6,
    PR3D_KEY_7 = GLFW_KEY_7,
    PR3D_KEY_8 = GLFW_KEY_8,
    PR3D_KEY_9 = GLFW_KEY_9,
    PR3D_KEY_SEMICOLON = GLFW_KEY_SEMICOLON, /* ; */
    PR3D_KEY_EQUAL = GLFW_KEY_EQUAL,         /* = */
    PR3D_KEY_A = GLFW_KEY_A,
    PR3D_KEY_B = GLFW_KEY_B,
    PR3D_KEY_C = GLFW_KEY_C,
    PR3D_KEY_D = GLFW_KEY_D,
    PR3D_KEY_E = GLFW_KEY_E,
    PR3D_KEY_F = GLFW_KEY_F,
    PR3D_KEY_G = GLFW_KEY_G,
    PR3D_KEY_H = GLFW_KEY_H,
    PR3D_KEY_I = GLFW_KEY_I,
    PR3D_KEY_J = GLFW_KEY_J,
    PR3D_KEY_K = GLFW_KEY_K,
    PR3D_KEY_L = GLFW_KEY_L,
    PR3D_KEY_M = GLFW_KEY_M,
    PR3D_KEY_N = GLFW_KEY_N,
    PR3D_KEY_O = GLFW_KEY_O,
    PR3D_KEY_P = GLFW_KEY_P,
    PR3D_KEY_Q = GLFW_KEY_Q,
    PR3D_KEY_R = GLFW_KEY_R,
    PR3D_KEY_S = GLFW_KEY_S,
    PR3D_KEY_T = GLFW_KEY_T,
    PR3D_KEY_U = GLFW_KEY_U,
    PR3D_KEY_V = GLFW_KEY_V,
    PR3D_KEY_W = GLFW_KEY_W,
    PR3D_KEY_X = GLFW_KEY_X,
    PR3D_KEY_Y = GLFW_KEY_Y,
    PR3D_KEY_Z = GLFW_KEY_Z,
    PR3D_KEY_LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET,   /* [ */
    PR3D_KEY_BACKSLASH = GLFW_KEY_BACKSLASH,         /* \ */
    PR3D_KEY_RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET, /* ] */
    PR3D_KEY_GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT,   /* ` */
    PR3D_KEY_WORLD_1 = GLFW_KEY_WORLD_1,             /* non-US #1 */
    PR3D_KEY_WORLD_2 = GLFW_KEY_WORLD_2,             /* non-US #2 */

    /* Function keys */
    PR3D_KEY_ESCAPE = GLFW_KEY_ESCAPE,
    PR3D_KEY_ENTER = GLFW_KEY_ENTER,
    PR3D_KEY_TAB = GLFW_KEY_TAB,
    PR3D_KEY_BACKSPACE = GLFW_KEY_BACKSPACE,
    PR3D_KEY_INSERT = GLFW_KEY_INSERT,
    PR3D_KEY_DELETE = GLFW_KEY_DELETE,
    PR3D_KEY_RIGHT = GLFW_KEY_RIGHT,
    PR3D_KEY_LEFT = GLFW_KEY_LEFT,
    PR3D_KEY_DOWN = GLFW_KEY_DOWN,
    PR3D_KEY_UP = GLFW_KEY_UP,
    PR3D_KEY_PAGE_UP = GLFW_KEY_PAGE_UP,
    PR3D_KEY_PAGE_DOWN = GLFW_KEY_PAGE_DOWN,
    PR3D_KEY_HOME = GLFW_KEY_HOME,
    PR3D_KEY_END = GLFW_KEY_END,
    PR3D_KEY_CAPS_LOCK = GLFW_KEY_CAPS_LOCK,
    PR3D_KEY_SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK,
    PR3D_KEY_NUM_LOCK = GLFW_KEY_NUM_LOCK,
    PR3D_KEY_PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN,
    PR3D_KEY_PAUSE = GLFW_KEY_PAUSE,
    PR3D_KEY_F1 = GLFW_KEY_F1,
    PR3D_KEY_F2 = GLFW_KEY_F2,
    PR3D_KEY_F3 = GLFW_KEY_F3,
    PR3D_KEY_F4 = GLFW_KEY_F4,
    PR3D_KEY_F5 = GLFW_KEY_F5,
    PR3D_KEY_F6 = GLFW_KEY_F6,
    PR3D_KEY_F7 = GLFW_KEY_F7,
    PR3D_KEY_F8 = GLFW_KEY_F8,
    PR3D_KEY_F9 = GLFW_KEY_F9,
    PR3D_KEY_F10 = GLFW_KEY_F10,
    PR3D_KEY_F11 = GLFW_KEY_F11,
    PR3D_KEY_F12 = GLFW_KEY_F12,
    PR3D_KEY_F13 = GLFW_KEY_F13,
    PR3D_KEY_F14 = GLFW_KEY_F14,
    PR3D_KEY_F15 = GLFW_KEY_F15,
    PR3D_KEY_F16 = GLFW_KEY_F16,
    PR3D_KEY_F17 = GLFW_KEY_F17,
    PR3D_KEY_F18 = GLFW_KEY_F18,
    PR3D_KEY_F19 = GLFW_KEY_F19,
    PR3D_KEY_F20 = GLFW_KEY_F20,
    PR3D_KEY_F21 = GLFW_KEY_F21,
    PR3D_KEY_F22 = GLFW_KEY_F22,
    PR3D_KEY_F23 = GLFW_KEY_F23,
    PR3D_KEY_F24 = GLFW_KEY_F24,
    PR3D_KEY_F25 = GLFW_KEY_F25,
    PR3D_KEY_KP_0 = GLFW_KEY_KP_0,
    PR3D_KEY_KP_1 = GLFW_KEY_KP_1,
    PR3D_KEY_KP_2 = GLFW_KEY_KP_2,
    PR3D_KEY_KP_3 = GLFW_KEY_KP_3,
    PR3D_KEY_KP_4 = GLFW_KEY_KP_4,
    PR3D_KEY_KP_5 = GLFW_KEY_KP_5,
    PR3D_KEY_KP_6 = GLFW_KEY_KP_6,
    PR3D_KEY_KP_7 = GLFW_KEY_KP_7,
    PR3D_KEY_KP_8 = GLFW_KEY_KP_8,
    PR3D_KEY_KP_9 = GLFW_KEY_KP_9,
    PR3D_KEY_KP_DECIMAL = GLFW_KEY_KP_DECIMAL,
    PR3D_KEY_KP_DIVIDE = GLFW_KEY_KP_DIVIDE,
    PR3D_KEY_KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY,
    PR3D_KEY_KP_SUBTRACT = GLFW_KEY_KP_SUBTRACT,
    PR3D_KEY_KP_ADD = GLFW_KEY_KP_ADD,
    PR3D_KEY_KP_ENTER = GLFW_KEY_KP_ENTER,
    PR3D_KEY_KP_EQUAL = GLFW_KEY_KP_EQUAL,
    PR3D_KEY_LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT,
    PR3D_KEY_LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL,
    PR3D_KEY_LEFT_ALT = GLFW_KEY_LEFT_ALT,
    PR3D_KEY_LEFT_SUPER = GLFW_KEY_LEFT_SUPER,
    PR3D_KEY_RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT,
    PR3D_KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
    PR3D_KEY_RIGHT_ALT = GLFW_KEY_RIGHT_ALT,
    PR3D_KEY_RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER,
    PR3D_KEY_MENU = GLFW_KEY_MENU
};

#endif
