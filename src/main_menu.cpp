#include <ncurses.h>
#include <string.h>

//-------------------------------------------------------------------//

#include "menu.h"
#include "custom_assert.h"

//———————————————————————————————————————————————————————————————————//

void MainMenuCtor(MainMenu_t* menu, int height, int width)
{
    ASSERT(menu)

    //-------------------------------------------------------------------//

    BackGroundCtor(&menu->background, height, width);
    // menu->height   = height / 2;
    // menu->width    = width  / 2 - 4,

    MenuCtor(&menu->menu, height / 2, width / 2, height / 4, width / 4);
    // menu->win      = CreateNewWin(height / 2 - 3, width / 2 - 4, (height - menu->height) / 2, (width - menu->width) / 2);
    // menu->nbuttons = nButtons;
    // menu->nstrings = nStrings;
    // MainMenuButtonsCtor(menu);

    OptionsCtor(&menu->options, 30, 40, 10, (width - 40) / 2);
    // menu->options_win = newwin(30, 40, 10, (width - 40) / 2);
    // menu->options_panel = new_panel(menu->options_win);
    // box(menu->options_win, 0, 0);
    // hide_panel(menu->options_panel);
    // wrefresh(menu->options_win);

    HelpCtor(&menu->help, 30, 40, 10, (width - 40) / 2);
    // menu->help_win = newwin(30, 40, 10, (width - 40) / 2);
    // menu->help_panel = new_panel(menu->options_win);
    // box(menu->help_win, 0, 0);
    // hide_panel(menu->help_panel);
    // wrefresh(menu->help_win);

    update_panels();
    do_update();
}

//===================================================================//

void BackGroundCtor(BackGround_t* background, int height, int width)
{
    ASSERT(background);

    //-------------------------------------------------------------------//

    background->height = height;
    background->width  = width;

    background->win    = CreateNewWin(height, width, 0, 0, false);
    background->panel  = new_panel(background->win);
}

//===================================================================//

void MenuCtor(Menu_t* menu, int height, int width, int y, int x)
{
    ASSERT(menu);

    menu->height = height;
    menu->width  = width;

    menu->y      = y;
    menu->x      = x;

    menu->win    = CreateNewWin(height, width, menu->y, menu->x, true);
    menu->panel  = new_panel(menu->win);

    menu->nbuttons = nButtons;
    menu->nstrings = nStrings;
    MainMenuButtonsCtor(menu);
}

//===================================================================//

void MainMenuButtonsCtor(Menu_t* menu)
{
    ASSERT(menu);

    for (int nbutton = 0; nbutton < menu->nbuttons; nbutton++)
    {
        menu->buttons[nbutton] = {.is_selected = !nbutton, // options defaultly selected
                                  .trigger     = Triggers[nbutton],
                                  .label       = Buttons[nbutton],
                                  .bold_label  = BoldButtons[nbutton],
                                  .label_len   = wcslen(BoldButtons[nbutton][0])};
    }
}

//===================================================================//

void HelpCtor(Help_t* help, int height, int width, int y, int x)
{
    ASSERT(help);

    help->height = height;
    help->width  = width;

    help->y      = y;
    help->x      = x;

    help->win    = CreateNewWin(height, width, y, x, true);
    help->panel  = new_panel(help->win);
    hide_panel(help->panel);
}

//===================================================================//

void MenuPrint(Menu_t* menu, int highlight)
{
    ASSERT(menu);
    ASSERT(menu->win);

    WINDOW* win = menu->win;

	box(win, 0, 0);

    for (int nbutton = 0; nbutton < menu->nbuttons; nbutton++)
    {
        Button_t button = menu->buttons[nbutton];

        for (int nstring = 0; nstring < menu->nstrings; nstring++)
        {
            const wchar_t* str = button.bold_label[nstring];

            if (highlight == nbutton)
                str = button.bold_label[nstring];
            else
                str = button.label[nstring];

            int row = 3*nbutton + nstring + 1;
            int col = (menu->width - (int) button.label_len) / 2 + 1;

            mvwprintw(win, row, col, "%ls", str);
        }

        addch('\n');
    }

    // refresh();
    wrefresh(win);
}

//===================================================================//

void ParseChoice(MainMenu_t* menu, int highlight)
{
    mvprintw(0, 0, "Chosen option %d", highlight);

    switch (highlight)
    {
        case 0:
            top_panel(menu->options.panel);
            show_panel(menu->options.panel);
            refresh();
            wrefresh(menu->options.win);
            getch();
            hide_panel(menu->options.panel);
            top_panel(menu->menu.panel);
            refresh();
            wrefresh(menu->options.win);
            update_panels();
            break;
        case 1:
            top_panel(menu->help.panel);
            show_panel(menu->help.panel);
            refresh();
            wrefresh(menu->help.win);
            getch();
            hide_panel(menu->help.panel);
            refresh();
            wrefresh(menu->help.win);
            top_panel(menu->menu.panel);
            update_panels();
            break;
        default:
            break;
    }
}

//———————————————————————————————————————————————————————————————————//
