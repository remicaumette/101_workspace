NAME=libft.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iincludes
SOURCES=srcs/ft_putchar.c	\
		srcs/ft_putstr.c	\
		srcs/ft_strcmp.c	\
		srcs/ft_strlen.c	\
		srcs/ft_swap.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
