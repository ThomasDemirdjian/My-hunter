/*
** EPITECH PROJECT, 2018
** rand
** File description:
** random
*/

#include "../include/my.h"

int	my_rand(int min, int max)
{
	int	rst = 0;
	int	div = max - min;

	srand(time(NULL));
	while ((rst = rand() % div) == 0);
	rst += min;
	return (rst);
}