NAME=fillit
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iinclude -I../libft/include
SOURCES=\
	src/main.c			\
	src/solver.c		\
	src/tetriminos.c	\
	src/parser.c
OBJECTS=$(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	@make -s -C ../libft
	$(CC) -L../libft -lft -o $(NAME) $(OBJECTS)

clean:
	make -C ../libft clean
	rm -f $(OBJECTS)

fclean: clean
	make -C ../libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
