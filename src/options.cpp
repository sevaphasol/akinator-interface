#include <panel.h>

#include "options.h"
#include "custom_assert.h"

//———————————————————————————————————————————————————————————————————//

int OptionsCtor(Options_t* options, int height, int width, int y, int x)
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

int OptionsPrint(Options_t* options, int height, int width, int y, int x)
{
    wprintw(options->win, "Developing...");

    return OK;
}

//———————————————————————————————————————————————————————————————————//
