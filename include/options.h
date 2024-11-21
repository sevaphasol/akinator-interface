#ifndef OPTIONS_H__
#define OPTIONS_H__

//———————————————————————————————————————————————————————————————————//

#include <panel.h>

#include "graphics.h"

//———————————————————————————————————————————————————————————————————//

struct Options_t
{
    int height, width;
	int y, x;

	WINDOW* win;
	PANEL*  panel;
};

//———————————————————————————————————————————————————————————————————//

int OptionsCtor  (Options_t* options,
                  int height, int width,
                  int y,      int x);

int OptionsPrint (Options_t* options);

//———————————————————————————————————————————————————————————————————//

#endif // OPTIONS_H__
