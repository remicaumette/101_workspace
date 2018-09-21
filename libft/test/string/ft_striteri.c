#include <stdio.h>
#include <string.h>
#include "libft.h"

void	print(unsigned int index, char *s)
{
	printf("%u - %s\n", index, s);
}

int		main(void)
{
	ft_striteri("hello world", print);
	return (0);
}