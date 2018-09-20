CC=gcc
CFLAGS=-Wall -Werror -Wextra -I../../include -L../.. -lft
EXECS=\
		ft_isalnum	\
		ft_isalpha	\
		ft_isascii	\
		ft_isdigit	\
		ft_isprint	\
		ft_tolower	\
		ft_toupper

all: $(EXECS)

clean:
	rm -f $(EXECS)

re: clean all

%: %.c
	$(CC) $(CFLAGS) $< -o $@
	./$@
