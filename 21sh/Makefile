NAME=21sh
LIBFT=./libft
CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(LIBFT)/include -Iinclude -g #-fsanitize=address
SOURCES=\
	src/lexer/lexer.c			\
	src/lexer/token.c			\
	src/lexer/utils.c			\
	src/parser/command.c		\
	src/parser/expansion.c		\
	src/parser/node.c			\
	src/parser/parser.c			\
	src/parser/redirection.c	\
	src/parser/utils.c			\
	src/environment.c			\
	src/history.c				\
	src/main.c					\
	src/shell.c
OBJECTS=$(SOURCES:.c=.o)
INCLUDES=\
	include/lexer.h				\
	include/parser.h			\
	include/shell.h

all: libft $(NAME)

libft:
	@make -s -C $(LIBFT)

$(NAME): $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) -L$(LIBFT) -lft -o $(NAME) $(OBJECTS)

clean:
	@make -s -C $(LIBFT) clean
	rm -f $(OBJECTS)

fclean: clean
	@make -s -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
