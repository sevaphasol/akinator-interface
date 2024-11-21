#ifndef MENU_H__
#define MENU_H__

struct Menu_t
{
    int height, width;
	int y, x;
	int nbuttons, nstrings;

	WINDOW* win;
	PANEL*  panel;

	Button_t buttons[nButtons];
};

struct Button_t
{
	bool   		 		   is_selected;
	int    		 		   trigger;
	const wchar_t* const * label;
	const wchar_t* const * bold_label;
	size_t 		 	       label_len;
};

#endif // MENU_H__
