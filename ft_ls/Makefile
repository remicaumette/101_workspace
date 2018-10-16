NAME=ft_ls
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iinclude -Ilibft/include -g -fsanitize=address
SOURCES=\
	src/main.c			\
	src/btree_file.c	\
	src/utils.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -s -C libft
	gcc -Llibft -fsanitize=address -lft -o $(NAME) $(OBJECTS)

clean:
	@make -C libft clean
	rm -f $(OBJECTS)

fclean: clean
	@make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
