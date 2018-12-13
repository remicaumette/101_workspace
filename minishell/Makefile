NAME=minishell
LIBFT=../libft
CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(LIBFT)/include -Iinclude -g
SOURCES=\
	src/builtin/cd.c		\
	src/builtin/echo.c		\
	src/builtin/env.c		\
	src/builtin/exit.c		\
	src/builtin/setenv.c	\
	src/builtin/unsetenv.c	\
	src/cmd.c				\
	src/main.c				\
	src/process.c			\
	src/shell.c				\
	src/utils.c				\
	src/words.c
OBJECTS=$(SOURCES:.c=.o)

all: libft $(NAME)

libft:
	@make -s -C $(LIBFT)

$(NAME): $(OBJECTS) include/minishell.h
	$(CC) $(CFLAGS) -L$(LIBFT) -lft -o $(NAME) $(OBJECTS)

clean:
	@make -s -C $(LIBFT) clean
	rm -f $(OBJECTS)

fclean: clean
	@make -s -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
