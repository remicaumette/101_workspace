#include <stdio.h>
#include <stdlib.h>

int		ft_sqrt(int nb);

int		main(int argc, char **argv)
{
	if (argc >= 2)
		printf("result: %d\n", ft_sqrt(atoi(argv[1])));
}

