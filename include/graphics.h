#ifndef GRAPHICS_H__
#define GRAPGICS_H__

#include <panel.h>

#include "menu.h"

const int nScreens = 10;

enum AkinUIStatus
{
    AKIN_UI_SUCCESS,
    AKIN_UI_NEWWIN_ERROR,
};

enum MessageBoxStatus
{
    MBOX_PASSIVE,
    MBOX_ACTIVE_INPUT,
    MBOX_ACTIVE_OUTPUT,
    MBOX_ACTIVE_INPUT_OUTPUT,
};

struct Graphics_t
{
    int rows, cols;

    // MessageBox_t message_box;
    MainMenu_t   main_menu;
    // Options_t    options;
    // Help_t       help;
    // Guessing_t   guessing;
    // Character_t  character;
    // Difference_t difference;
};

struct MessageBox_t
{
    MessageBoxStatus status;
    WINDOW*          win;
    PANEL*           panel;
};

void GraphicsCtor(Graphics_t* graphics, int rows, int cols);
WINDOW* CreateNewWin(int height, int width, int y, int x, bool need_box);

#endif // GRAPGICS_H__
