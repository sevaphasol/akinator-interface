#include <ncurses.h>

//-------------------------------------------------------------------//

#include "menu.h"
#include "custom_assert.h"

//———————————————————————————————————————————————————————————————————//

WINDOW* CreateNewWin(int height, int width, int y, int x)
{
    WINDOW* win;

	win = newwin(height, width, y, x);
	box(win, 0 , 0);
	wrefresh(win);

	return win;
}

//===================================================================//

void MenuCtor(Menu_t* menu, int height, int width, int y, int x)
{
    ASSERT(menu)

    //-------------------------------------------------------------------//

    menu->win    = CreateNewWin(height, width, y, x);
    menu->height = height;
    menu->width  = width,
    menu->x      = x;
    menu->y      = y;

    refresh();
}

//===================================================================//

void MenuPrint(Menu_t* menu, int highlight)
{
    ASSERT(menu);
    ASSERT(menu->win);

    //-------------------------------------------------------------------//

    for (int nbutton = 0; nbutton < nButtons; nbutton++)
    {
        for (int nstring = 0; nstring < nStrings; nstring++)
        {
            mvwprintw(menu->win,
                      3*nbutton + nstring, 0,
                      "%s\n", (nbutton == highlight) ? \
                      BoldButtons[nbutton][nstring] : Buttons[nbutton][nstring]);
        }

        addch('\n');
    }

    wrefresh(menu->win);
}

//===================================================================//

void ParseChoice(int highlight)
{
    mvprintw(0, 0, "Chosen option %d", highlight);

    refresh();
}

//———————————————————————————————————————————————————————————————————//
