CC=gcc
CFLAGS=-Wall -Werror -Wextra -I../../include -L../.. -lft
EXECS=\
		ft_memccpy

all: $(EXECS)

clean:
	rm -f $(EXECS)

re: clean all

%: %.c
	$(CC) $(CFLAGS) $< -o $@
	./$@
