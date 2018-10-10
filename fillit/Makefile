NAME=fillit
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iinclude -Ilibft/include -g
SOURCES=\
	src/main.c			\
	src/solver.c		\
	src/tetriminos.c	\
	src/parser.c
OBJECTS=$(SOURCES:.c=.o)


all: libft $(NAME)

libft:
	make -C libft

$(NAME): $(OBJECTS)
	gcc -Llibft -lft -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: libft all clean fclean re
