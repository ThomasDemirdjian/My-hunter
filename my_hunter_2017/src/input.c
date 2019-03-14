/*
** EPITECH PROJECT, 2018
** input
** File description:
** input
*/

#include "../include/my.h"

void	my_input(t_input *input, t_window *win)
{
	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
		if ((win->event).type == sfEvtClosed)
			sfRenderWindow_close(win->window);
		if ((win->event).type == sfEvtMouseButtonPressed && win->bullet > 0) {
			input->click_l = 1;
			win->bullet--;
		}
		else
			input->click_l = 0;
		if (sfKeyboard_isKeyPressed(sfKeyR) == 1)
			win->bullet = 6;
	}
}