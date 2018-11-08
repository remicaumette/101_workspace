NAME=libft.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iinclude
SOURCES=\
	src/io/ft_print_memory.c			\
	src/io/ft_print_memory_fd.c			\
	src/io/ft_putchar_fd.c				\
	src/io/ft_putchar.c					\
	src/io/ft_putendl_fd.c				\
	src/io/ft_putendl.c					\
	src/io/ft_putnbr_fd.c				\
	src/io/ft_putnbr.c					\
	src/io/ft_putstr_fd.c				\
	src/io/ft_putstr.c					\
	src/io/get_next_line.c				\
	src/std/ft_bzero.c					\
	src/std/ft_memalloc.c				\
	src/std/ft_memccpy.c				\
	src/std/ft_memchr.c					\
	src/std/ft_memcmp.c					\
	src/std/ft_memcpy.c					\
	src/std/ft_memdel.c					\
	src/std/ft_memmove.c				\
	src/std/ft_memset.c					\
	src/strconv/ft_atoi.c				\
	src/strconv/ft_atol.c				\
	src/strconv/ft_atoll.c				\
	src/strconv/ft_itoa.c				\
	src/strconv/ft_lltoa.c				\
	src/strconv/ft_ltoa.c				\
	src/string/ft_strarr_add.c			\
	src/string/ft_strarr_del.c			\
	src/string/ft_strarr_len.c			\
	src/string/ft_strcat.c				\
	src/string/ft_strchr.c				\
	src/string/ft_strclr.c				\
	src/string/ft_strcmp.c				\
	src/string/ft_strcpy.c				\
	src/string/ft_strdel.c				\
	src/string/ft_strdup.c				\
	src/string/ft_strequ.c				\
	src/string/ft_striter.c				\
	src/string/ft_striteri.c			\
	src/string/ft_strjoin.c				\
	src/string/ft_strlcat.c				\
	src/string/ft_strlen.c				\
	src/string/ft_strmap.c				\
	src/string/ft_strmapi.c				\
	src/string/ft_strncat.c				\
	src/string/ft_strncmp.c				\
	src/string/ft_strncpy.c				\
	src/string/ft_strnequ.c				\
	src/string/ft_strnew.c				\
	src/string/ft_strnstr.c				\
	src/string/ft_strrchr.c				\
	src/string/ft_strsplit.c			\
	src/string/ft_strstr.c				\
	src/string/ft_strsub.c				\
	src/string/ft_strtrim.c				\
	src/type/ft_isalnum.c				\
	src/type/ft_isalpha.c				\
	src/type/ft_isascii.c				\
	src/type/ft_isdigit.c				\
	src/type/ft_isprint.c				\
	src/type/ft_tolower.c				\
	src/type/ft_toupper.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
