/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my_hunter
*/

#ifndef MY_H_
# define MY_H_

# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <stddef.h>

typedef	struct	s_window
{
	sfRenderWindow	*window;
	sfVideoMode	video;
	sfEvent		event;
	int		bullet;
} t_window;

typedef	struct	s_sprite
{
	sfSprite	*back;
	sfSprite	*duck;
	sfSprite	*bullet;
	sfSprite	*reload;
	sfVector2f	pos;
	sfIntRect	rect;
	sfClock		*clock;
	float		r_duck;
} t_sprite;

typedef	struct	s_input
{
	int	click_l;
	int	click_r;
} t_input;

int		my_rand(int min, int max);
int		check_hit(t_window *win, t_sprite *sprite);
int		check_start_screen(t_sprite *sprite);
int		check_end_screen(t_window *win, t_sprite *sprite);
void		my_input(t_input *input, t_window *win);
void		move_duck(t_window *win, t_sprite *sprite);
void		change_rect(t_sprite *sprite);
void		display(t_window *win, t_sprite *sprite);
t_window	*set_window(void);
t_sprite	*set_sprite(void);
sfSprite	*create_sprite(char *path);
sfIntRect	create_rect(int left, int top, int width, int height);

#endif /* !MY_H_ */
