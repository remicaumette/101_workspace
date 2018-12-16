NAME=ft_select
LIBFT=libft
CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(LIBFT)/include -Iinclude
SOURCES=\
	src/main.c
OBJECTS=$(SOURCES:.c=.o)
INCLUDES=\
	include/ft_select.h

all: libft $(NAME)

libft:
	@make -s -C $(LIBFT)

$(NAME): $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) -L$(LIBFT) -lft -ltermcap -o $(NAME) $(OBJECTS)

clean:
	@make -s -C $(LIBFT) clean
	rm -f $(OBJECTS)

fclean: clean
	@make -s -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
