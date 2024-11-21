#include "graphics.h"
#include "menu.h"

//———————————————————————————————————————————————————————————————————//

int GraphicsCtor(Graphics_t* graphics, int rows, int cols)
{
    graphics->rows = rows;
    graphics->cols = cols;

    RETURN_IF_ERR(MainMenuCtor(&graphics->main_menu,
                                graphics->rows, graphics->cols));

    return AKIN_UI_SUCCESS;

}

//===================================================================//

int CreateNewWin(WINDOW** ret_win,
                          int height, int width,
                          int y,      int x,
                          bool need_box)
{
    ASSERT(ret_win);

    WINDOW* win = newwin(height, width, y, x);

    if (!win), return ERR);

	if (need_box)
    {
        box(win, 0 , 0);
    }

    wrefresh(win);

    *ret_win = win;

    return OK;
}

//———————————————————————————————————————————————————————————————————//
