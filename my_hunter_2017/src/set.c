/*
** EPITECH PROJECT, 2018
** set
** File description:
** set
*/

#include "../include/my.h"

sfSprite	*create_sprite(char *path)
{
	sfTexture	*texture = sfTexture_createFromFile(path, NULL);
	sfSprite	*sprite = sfSprite_create();

	sfSprite_setTexture(sprite, texture, sfFalse);
	return (sprite);
}

sfIntRect	create_rect(int left, int top, int width, int height)
{
	sfIntRect	rect;

	rect.left = left;
	rect.top = top;
	rect.width = width;
	rect.height= height;
	return (rect);
}

sfSprite	*set_scale(float x, float y, sfSprite *sprite)
{
	sfVector2f	scale;

	scale.x = x;
	scale.y = y;
	sfSprite_scale(sprite, scale);
	return (sprite);
}

t_sprite	*set_sprite(void)
{
	t_sprite	*sprite = malloc(sizeof(struct s_sprite));

	sprite->back = create_sprite("image/background.png");
	sprite->duck = create_sprite("image/spritesheet.png");
	sprite->bullet = create_sprite("image/bullet.png");
	sprite->reload = create_sprite("image/reload.png");
	sprite->bullet = set_scale(0.5, 0.5, sprite->bullet);
	sprite->reload = set_scale(0.25, 0.25, sprite->reload);
	sprite->rect = create_rect(110, 0, 110, 110);
	sfSprite_setTextureRect(sprite->duck, sprite->rect);
	sprite->pos.x = 0.0;
	sprite->pos.y = 0.0;
	sprite->clock = sfClock_create();
	return (sprite);
}

t_window	*set_window(void)
{
	t_window	*win = malloc(sizeof(struct s_window));
	
	win->video.width = 1280;
	win->video.height = 769;
	win->window = sfRenderWindow_create(win->video, "My_hunter",
	sfResize | sfClose, NULL);
	win->bullet = 6;
	return (win);
}