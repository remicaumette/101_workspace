NAME=ft_select
LIBFT=libft
CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(LIBFT)/include -Iinclude
SOURCES=\
	src/action/action_arrow_down.c	\
	src/action/action_arrow_left.c	\
	src/action/action_arrow_right.c	\
	src/action/action_arrow_up.c	\
	src/action/action_backspace.c	\
	src/action/action_esc.c			\
	src/action/action_espace.c		\
	src/action/action_return.c		\
	src/main.c						\
	src/select_action_dispatcher.c	\
	src/select_destroy.c			\
	src/select_entry_at.c			\
	src/select_entry_create.c		\
	src/select_entry_destroy.c		\
	src/select_init.c				\
	src/select_render.c				\
	src/select_start.c
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
