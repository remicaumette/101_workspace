NAME=minishell
LIBFT=../libft
CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(LIBFT)/include -Iinclude -g -fsanitize=address
SOURCES=\
	src/builtin/cd.c	\
	src/builtin/env.c	\
	src/builtin/exit.c	\
	src/cmd.c			\
	src/main.c			\
	src/process.c		\
	src/shell.c			\
	src/utils.c			\
	src/words.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -s -C $(LIBFT)
	$(CC) $(CFLAGS) -L$(LIBFT) -lft -o $(NAME) $(OBJECTS)

clean:
	@make -s -C $(LIBFT) clean
	rm -f $(OBJECTS)

fclean: clean
	@make -s -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
