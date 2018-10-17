NAME=ft_ls
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iinclude -Ilibft/include -g -fsanitize=address
SOURCES=\
	src/dirinfo.c		\
	src/fileinfo.c		\
	src/format.c		\
	src/main.c			\
	src/sort.c			\
	src/utils.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -s -C libft
	gcc -Llibft -lft -o $(NAME) $(OBJECTS) -g -fsanitize=address

clean:
	@make -C libft clean
	rm -f $(OBJECTS)

fclean: clean
	@make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
