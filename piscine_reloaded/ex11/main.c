#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int		main(void)
{
	int div = 0;
	int mod = 0;
	printf("div: %d mod: %d\n", div, mod);
	ft_div_mod(5, 2, &div, &mod);
	printf("div: %d mod: %d\n", div, mod);
}

