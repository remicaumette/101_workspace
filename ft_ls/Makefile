NAME=ft_ls
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iinclude -Ilibft
SOURCES=\
	src/main.c
OBJECTS=$(SOURCES:.c=.o)

all: libft $(NAME)

libft:
	make -C libft

$(NAME): $(OBJECTS)
	gcc -Llibft -lft -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
