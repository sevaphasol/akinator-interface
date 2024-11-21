
#include <ncurses.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#include "graphics.h"
#include "menu.h"

int main()
{
    setlocale(LC_ALL, "");

    initscr();
    cbreak();
    noecho();
    start_color();
    curs_set(0);
    init_pair(1,COLOR_WHITE, COLOR_BLACK);
    bkgd(COLOR_PAIR(1));

    initscr();
    cbreak();
    noecho();

    int rows, cols = 0;
    getmaxyx(stdscr, rows, cols);

    // Graphics_t graphics = {};

    // GraphicsCtor(&graphics, rows, cols);

    MainMenu_t menu = {};
    MainMenuCtor(&menu, rows, cols);

    keypad(menu.menu.win, TRUE);

    int highlight = 0;
    int running   = true;
    MenuPrint(&menu.menu, highlight);

    while (running)
    {
        switch(wgetch(menu.menu.win))
        {
            case KEY_UP:
                (highlight == 0) ? highlight = nButtons - 1 : --highlight;
                break;
			case KEY_DOWN:
                (highlight == nButtons - 1) ? highlight = 0 : ++highlight;
                break;
			case '\n':
				ParseChoice(&menu, highlight);
				break;
            case 'q':
                running = false;
                break;
			default:
				refresh();
				break;
        }

        MenuPrint(&menu.menu, highlight);
    }

    refresh();
    endwin();

    return 0;
}

