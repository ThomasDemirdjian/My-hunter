##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my_hunter
##

CC =	gcc

NAME =	my_hunter

SRC =	src/main.c	\
	src/set.c	\
	src/input.c	\
	src/tools.c	\
	src/check.c	\
	src/display.c	\
	src/move.c

OBJS =	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean mr_clean re
