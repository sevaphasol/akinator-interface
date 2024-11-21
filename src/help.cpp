#include <panel.h>

#include "help.h"
#include "custom_assert.h"

//———————————————————————————————————————————————————————————————————//

int HelpCtor(Help_t* options, int height, int width, int y, int x)
{
    ASSERT(options);

    options->height = height;
    options->width  = width;

    options->y      = y;
    options->x      = x;

    options->win    = CreateNewWin(height, width, y, x, true);
    options->panel  = new_panel(options->win);
    hide_panel(options->panel);

    return OK;
}

//===================================================================//

int HelpPrint(Help_t* help)
{
    wprintw(options->win, "Developing...");

    return OK;
}

//———————————————————————————————————————————————————————————————————//
