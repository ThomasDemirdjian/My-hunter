/*
** EPITECH PROJECT, 2018
** check
** File description:
** check
*/

#include "../include/my.h"

int	check_end_screen(t_window *win, t_sprite *sprite)
{
	sfVector2f pos_sprite = sfSprite_getPosition(sprite->duck);
	sfVector2u pos_win = sfRenderWindow_getSize(win->window);

	if ((int)pos_sprite.x > (int)pos_win.x)
		return (-1);
	return (0);
}

int	check_start_screen(t_sprite *sprite)
{
	sfVector2f pos_sprite = sfSprite_getPosition(sprite->duck);

	if ((int)pos_sprite.x < 0)
		return (-1);
	return (0);
}

int	check_hit(t_window *win, t_sprite *sprite)
{
	sfVector2f	pos = sfSprite_getPosition(sprite->duck);
	sfVector2f	scale = sfSprite_getScale(sprite->duck);
	float		m_x = win->event.mouseButton.x;
	float		m_y = win->event.mouseButton.y;

	if (scale.x == 1.0) {
		if ((m_x > pos.x && m_x < (pos.x + 110)) &&
		(m_y > pos.y && m_y < (pos.y + 110)))
			return (1);
	}
	else if (scale.x == -1.0) {
		if ((m_x < pos.x && m_x > (pos.x - 110)) &&
		(m_y > pos.y && m_y < (pos.y + 110)))
			return (1);
	}
	return (0);
}