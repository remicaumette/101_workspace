NAME=display_file
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iinclude
SOURCES=src/main.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all