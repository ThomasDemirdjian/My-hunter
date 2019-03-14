/*
** EPITECH PROJECT, 2018
** display
** File description:
** display
*/

#include "../include/my.h"

void	change_rect(t_sprite *sprite)
{
	sfTime	time = sfClock_getElapsedTime(sprite->clock);
	float	seconde = sfTime_asSeconds(time);

	if (sprite->rect.left == 330)
		sprite->rect.left = 0;
	sprite->rect = create_rect(sprite->rect.left, 0, 110, 110);
	sfSprite_setTextureRect(sprite->duck, sprite->rect);
	if (seconde > 0.1) {
		sprite->rect.left += 110;
		sfClock_restart(sprite->clock);
	}
}

void	print_reload(t_window *win, t_sprite *sprite)
{
	sfVector2f pos;

	pos.x = 0.0;
	pos.y = 640.0;
	sfSprite_setPosition(sprite->reload, pos);
	sfRenderWindow_drawSprite(win->window, sprite->reload, NULL);
}

void	print_bullet(t_window *win, t_sprite *sprite)
{
	sfVector2f	pos;
	int		i = 0;

	pos.x = -10.0;
	pos.y = 669.0;
	if (win->bullet == 0)
		print_reload(win, sprite);
	else {
		while (i != win->bullet) {
			sfSprite_setPosition(sprite->bullet, pos);
			sfRenderWindow_drawSprite(win->window, sprite->bullet, NULL);
			pos.x += 50.0;
			i++;
		}
	}
}

void	display(t_window *win, t_sprite *sprite)
{
	sfRenderWindow_drawSprite(win->window, sprite->back, NULL);
	print_bullet(win, sprite);
	sfRenderWindow_drawSprite(win->window, sprite->duck, NULL);
	sfRenderWindow_display(win->window);
}