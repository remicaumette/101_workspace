NAME=ft_ls
LIBFT=../libft
CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(LIBFT)/include -Iinclude
SOURCES=\
	src/display/vertical.c		\
	src/display/horizontal.c	\
	src/display/long_format.c	\
	src/display/one_per_line.c	\
	src/display/with_commas.c	\
	src/dirinfo.c				\
	src/fileinfo.c				\
	src/ls.c					\
	src/main.c					\
	src/options.c				\
	src/sort.c					\
	src/utils.c
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
