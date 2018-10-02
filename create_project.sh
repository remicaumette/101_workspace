if [ -z "$1" ]; then
	echo "$0 <project name>"
	exit 1
fi

if [ -d "$1" ]; then
	echo "Project already exists! Please delete the directory."
	exit 1
fi

echo "Creating structure..."
mkdir -p $1/{src,include}
echo "Copying libft..."
cp -r libft $1/libft
echo "Cleanup libft..."
rm -rf $1/libft/{test,.gitignore,auteur}

echo "Generating $1/Makefile..."
cat <<EOF >$1/Makefile
NAME=$1
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Iinclude -Ilibft/include
SOURCES=\\
	src/main.c
OBJECTS=\$(SOURCES:.c=.o)

all: libft \$(NAME)

libft:
	make -C libft

\$(NAME): \$(OBJECTS)
	gcc -Llibft -lft -o \$(NAME) \$(OBJECTS)

clean:
	rm -f \$(OBJECTS)

fclean: clean
	rm -f \$(NAME)

re: fclean all
EOF

echo "Generating $1/include/$1.h..."
cat <<EOF >$1/include/$1.h
#ifndef $(echo $1 | tr '[a-z]' '[A-Z]')_H
# define $(echo $1 | tr '[a-z]' '[A-Z]')_H
# include "libft.h"
#endif
EOF

echo "Generating $1/src/main.c..."
cat <<EOF >$1/src/main.c
#include "$1.h"

int	main(void)
{
	ft_putendl("Hello world!");
}
EOF

echo "Generating $1/.gitignore..."
cat <<EOF >$1/.gitignore
$1
EOF

echo "Generating $1/auteur..."
cat <<EOF >$1/auteur
rcaumett
EOF

echo "Done!"