#include "ft_ls.h"

int	ls(char *path)
{
	if ()
	return (0);
}

int	main(int argc, char **argv)
{
	int i;
	int code;

	i = 0;
	code = 0;
	while (++i < argc)
		code |= ls(argv[i]);
	return (code);
}
