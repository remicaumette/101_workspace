NAME=ft_ls
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iinclude -Ilibft/include
SOURCES=\
	src/main.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -s -C libft
	gcc -Llibft -lft -o $(NAME) $(OBJECTS)

clean:
	@make -C libft clean
	rm -f $(OBJECTS)

fclean: clean
	@make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
