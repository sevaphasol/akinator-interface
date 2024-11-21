#ifndef MENU_H__
#define MENU_H__

//———————————————————————————————————————————————————————————————————//

#include <panel.h>

//———————————————————————————————————————————————————————————————————//

const int nButtons = 6;
const int nStrings = 3;

const wchar_t* const Buttons[nButtons][nStrings] =
{
	{
		L"┌─┐┌─┐┌┬┐┬┌─┐┌┐┌┌─┐",
		L"│ │├─┘ │ ││ ││││└─┐",
		L"└─┘┴   ┴ ┴└─┘┘└┘└─┘"
	},

	{
		L"┬ ┬┌─┐┬  ┌─┐",
		L"├─┤├┤ │  ├─┘",
		L"┴ ┴└─┘┴─┘┴  "
	},

	{
		L"┌─┐┬ ┬┌─┐┌─┐┌─┐┬┌┐┌┌─┐",
		L"│ ┬│ │├┤ └─┐└─┐│││││ ┬",
		L"└─┘└─┘└─┘└─┘└─┘┴┘└┘└─┘"
	},

	{
		L"┌─┐┬ ┬┌─┐┬─┐┌─┐┌─┐┌┬┐┌─┐┬─┐┬┌─┐┌┬┐┬┌─┐",
		L"│  ├─┤├─┤├┬┘├─┤│   │ ├┤ ├┬┘│└─┐ │ ││  ",
		L"└─┘┴ ┴┴ ┴┴└─┴ ┴└─┘ ┴ └─┘┴└─┴└─┘ ┴ ┴└─┘"
	},

	{
		L"┌┬┐┬┌─┐┌─┐┌─┐┬─┐┌─┐┌┐┌┌─┐┌─┐",
		L" │││├┤ ├┤ ├┤ ├┬┘├┤ ││││  ├┤ ",
		L"─┴┘┴└  └  └─┘┴└─└─┘┘└┘└─┘└─┘"
	},

	{
		L"┌─┐ ┬ ┬┬┌┬┐",
		L"│─┼┐│ ││ │ ",
		L"└─┘└└─┘┴ ┴ "
	}
};

const wchar_t* const BoldButtons[nButtons][nStrings] =
{
	{
		L"╔═╗╔═╗╔╦╗╦╔═╗╔╗╔╔═╗",
		L"║ ║╠═╝ ║ ║║ ║║║║╚═╗",
		L"╚═╝╩   ╩ ╩╚═╝╝╚╝╚═╝"
	},

	{
		L"╦ ╦╔═╗╦  ╔═╗",
		L"╠═╣║╣ ║  ╠═╝",
		L"╩ ╩╚═╝╩═╝╩  "
	},

	{
		L"╔═╗╦ ╦╔═╗╔═╗╔═╗╦╔╗╔╔═╗",
		L"║ ╦║ ║║╣ ╚═╗╚═╗║║║║║ ╦",
		L"╚═╝╚═╝╚═╝╚═╝╚═╝╩╝╚╝╚═╝"
	},

	{
		L"╔═╗╦ ╦╔═╗╦═╗╔═╗╔═╗╔╦╗╔═╗╦═╗╦╔═╗╔╦╗╦╔═╗",
		L"║  ╠═╣╠═╣╠╦╝╠═╣║   ║ ║╣ ╠╦╝║╚═╗ ║ ║║  ",
		L"╚═╝╩ ╩╩ ╩╩╚═╩ ╩╚═╝ ╩ ╚═╝╩╚═╩╚═╝ ╩ ╩╚═╝"
	},

	{
		L"╔╦╗╦╔═╗╔═╗╔═╗╦═╗╔═╗╔╗╔╔═╗╔═╗",
		L" ║║║╠╣ ╠╣ ║╣ ╠╦╝║╣ ║║║║  ║╣ ",
		L"═╩╝╩╚  ╚  ╚═╝╩╚═╚═╝╝╚╝╚═╝╚═╝"
	},

	{
		L"╔═╗ ╦ ╦╦╔╦╗",
		L"║═╬╗║ ║║ ║ ",
		L"╚═╝╚╚═╝╩ ╩ "
	}
};

const char Triggers[nButtons] = {'o', 'h', 'g', 'c', 'd', 'q'};

//———————————————————————————————————————————————————————————————————//

struct BackGround_t
{
	int height, width;

	WINDOW* win;
	PANEL*  panel;
};





//-------------------------------------------------------------------//

struct MainMenu_t
{
	BackGround_t background;
	Menu_t       menu;
	Options_t    options;
	Help_t 		 help;
};

//———————————————————————————————————————————————————————————————————//

void BackGroundCtor(BackGround_t* background, int height, int width);



void    MainMenuCtor (MainMenu_t* menu,
					  int height, int width);

void BackGroundCtor	(BackGround_t* background, int height, int width);

void MenuCtor		(Menu_t* menu, int height, int width, int y, int x);

void MainMenuButtonsCtor(Menu_t* menu);



void    MenuPrint    (Menu_t* menu, int highlight);

void 	ParseChoice(MainMenu_t* menu, int highlight);

void    MainMenuButtonsCtor(Menu_t* menu);

//———————————————————————————————————————————————————————————————————//

 #endif // MENU_H__
