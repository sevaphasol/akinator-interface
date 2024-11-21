#ifndef HELP_H__
#define HELP_H__

//———————————————————————————————————————————————————————————————————//

#include <panel.h>

#include "graphics.h"

//———————————————————————————————————————————————————————————————————//

struct Help_t
{
    int height, width;
	int y, x;

	WINDOW* win;
	PANEL*  panel;
};

//———————————————————————————————————————————————————————————————————//

int HelpCtor  (Help_t* options,
               int height, int width,
               int y,      int x);

int HelpPrint (Help_t* help);

//———————————————————————————————————————————————————————————————————//

#endif // HELP_H__
