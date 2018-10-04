#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char *mem1 = ft_strdup("hello world!");
	int		tab[15] = {0,15,54,42,42,42,42,42,97,127};
	ft_print_memory(tab, sizeof(tab));
	ft_putchar('\n');
	char *mem2 = ft_strdup("ewieweiwweewewioweijwewioewiowdnoidwiowd wddwdwdw 5648wd48dw46dw4 48d48dw  \1 wkeweuwhewiuw!");
	ft_print_memory(mem2, 94);
}
