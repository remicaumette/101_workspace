NAME=ft_printf
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iinclude -I../libft/include
SOURCES=\
	src/main.c
OBJECTS=$(SOURCES:.c=.o)

all: libft $(NAME)

libft:
	make -C ../libft

$(NAME): $(OBJECTS)
	gcc -L../libft -lft -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
