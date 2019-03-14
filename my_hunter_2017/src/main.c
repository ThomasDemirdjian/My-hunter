/*
** EPITECH PROJECT, 2018
** main
** File description:
** my_hunter
*/

#include "../include/my.h"

void	next_duck(t_sprite *sprite)
{
	sprite->pos.x = 0.0;
	sprite->pos.y = (float)my_rand(0, 400);
	sfSprite_setPosition(sprite->duck, sprite->pos);
}

void	duck(t_window *win, t_input *input, t_sprite *sprite)
{
	move_duck(win, sprite);
	if (input->click_l == 1 && (win->bullet > 0)
	&& (check_hit(win, sprite) == 1))
		next_duck(sprite);
}

void	destroy_everything(t_window *win, t_sprite *sprite, t_input *input)
{
	sfSprite_destroy(sprite->back);
	sfSprite_destroy(sprite->duck);
	sfSprite_destroy(sprite->bullet);
	sfSprite_destroy(sprite->reload);
	sfRenderWindow_destroy(win->window);
	free(win);
	free(sprite);
	free(input);
}

int	main()
{
	t_window	*win = set_window();
	t_sprite	*sprite = set_sprite();
	t_input		*input = malloc(sizeof(struct s_input));

	if (!win->window)
		return (84);
	sfRenderWindow_setFramerateLimit(win->window, 120);
	sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
	while (sfRenderWindow_isOpen(win->window)) {
		my_input(input, win);
		duck(win, input, sprite);
	}
	destroy_everything(win, sprite, input);
	return (0);
}