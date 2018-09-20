#include <stdio.h>

int	ft_count_if(char **tab, int (*f)(char *));

int	ft_cmp(char *s)
{
	return *s == 's';
}

int main(int argc, char **argv)
{
	if (argc)
		printf("%d\n", ft_count_if(argv, ft_cmp));
}
