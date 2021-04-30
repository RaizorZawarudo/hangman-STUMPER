##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## .
##

SRC	=	src/main.c \
		src/load_file.c	\
		src/error_handler.c \
		src/gameloop.c	\
		src/utils.c

NAME	=	hangman

INC	=	-I include/

LMY	=	-L lib/my/ -lmy

all:	$(NAME) clean

$(NAME):
	make -C ./lib/my/
	gcc $(SRC) -o $(NAME) $(LMY) $(INC) -g3

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all