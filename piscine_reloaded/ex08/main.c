#include <unistd.h>
#include <stdlib.h>

void	ft_is_negative(int n);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
		ft_is_negative(atoi(argv[1]));
}

