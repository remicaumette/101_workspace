NAME=libft.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iinclude
SOURCES=\
	src/container/ft_lstadd.c		\
	src/container/ft_lstdel.c		\
	src/container/ft_lstdelone.c	\
	src/container/ft_lstiter.c		\
	src/container/ft_lstmap.c		\
	src/container/ft_lstnew.c		\
	src/io/ft_putchar_fd.c			\
	src/io/ft_putchar.c				\
	src/io/ft_putendl_fd.c			\
	src/io/ft_putendl.c				\
	src/io/ft_putnbr_fd.c			\
	src/io/ft_putnbr.c				\
	src/io/ft_putstr_fd.c			\
	src/io/ft_putstr.c				\
	src/std/ft_atoi.c				\
	src/std/ft_bzero.c				\
	src/std/ft_memalloc.c			\
	src/std/ft_memccpy.c			\
	src/std/ft_memcpy.c				\
	src/std/ft_memdel.c				\
	src/std/ft_memset.c				\
	src/string/ft_strclr.c			\
	src/string/ft_strcmp.c			\
	src/string/ft_strcpy.c			\
	src/string/ft_strdel.c			\
	src/string/ft_strdup.c			\
	src/string/ft_strequ.c			\
	src/string/ft_striter.c			\
	src/string/ft_striteri.c		\
	src/string/ft_strlen.c			\
	src/string/ft_strmap.c			\
	src/string/ft_strmapi.c			\
	src/string/ft_strncmp.c			\
	src/string/ft_strnequ.c			\
	src/string/ft_strnew.c			\
	src/string/ft_strsub.c			\
	src/string/ft_strtrim.c			\
	src/type/ft_isalnum.c			\
	src/type/ft_isalpha.c			\
	src/type/ft_isascii.c			\
	src/type/ft_isdigit.c			\
	src/type/ft_isprint.c			\
	src/type/ft_tolower.c			\
	src/type/ft_toupper.c

OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcvs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
