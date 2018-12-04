NAME=minishell
LIBFT=../libft
CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(LIBFT)/include -Iinclude -g -fsanitize=address
SOURCES=\
	src/lexer/token.c		\
	src/lexer/tokenize.c	\
	src/command.c	\
	src/main.c		\
	src/minishell.c
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
