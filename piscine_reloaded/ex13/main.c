#include <stdio.h>
#include <stdlib.h>

int		ft_recursive_factorial(int nb);

int		main(int argc, char **argv)
{
	if (argc >= 2)
		printf("result: %d\n", ft_recursive_factorial(atoi(argv[1])));
}

