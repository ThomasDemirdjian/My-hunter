/*
** EPITECH PROJECT, 2018
** move
** File description:
** move
*/

#include "../include/my.h"

void	move_right(t_sprite *sprite)
{
	sfVector2f	pos;
	sfVector2f	ret;
	sfVector2f	scale = sfSprite_getScale(sprite->duck);

	pos.x = 3.0;
	pos.y = 0.0;
	if (scale.x != 1.0) {
		ret.x = -1.0;
		ret.y = 1.0;
		sfSprite_scale(sprite->duck, ret);
	}
	sfSprite_move(sprite->duck, pos);
}

void	move_left(t_sprite *sprite)
{
	sfVector2f	pos;
	sfVector2f	ret;
	sfVector2f	scale = sfSprite_getScale(sprite->duck);

	pos.x = -3.0;
	pos.y = 0.0;
	if (scale.x != -1.0) {
		ret.x = -1.0;
		ret.y = 1.0;
		sfSprite_scale(sprite->duck, ret);
	}
	sfSprite_move(sprite->duck, pos);
}

void	move_duck(t_window *win, t_sprite *sprite)
{
	static int end = 0;

	if (check_end_screen(win, sprite) == -1)
		end = 1;
	else if (check_start_screen(sprite) == -1)
		end = 0;
	change_rect(sprite);
	if (end == 1)
		move_left(sprite);
	else
		move_right(sprite);
	display(win, sprite);
}