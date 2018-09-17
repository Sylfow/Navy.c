##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## for navy
##

SRC	=	src/main.c	\
		src/game.c	\
		src/player_turn.c	\
		src/map.c	\
		src/win_condition.c	\
		lib/my_itoa.c	\
		lib/my_atoi.c	\
		lib/my_putchar.c	\
		lib/my_putstr.c	\
		lib/get_next_line.c	\
		lib/my_strlen.c	\
		lib/my_put_nbr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-W -Wall -Wextra -I include -g

LDFLAGS	=	-L lib -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc lib/libmy.a $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f lib/libmy.a

re:	fclean all

.PHONY:	all clean fclean re
