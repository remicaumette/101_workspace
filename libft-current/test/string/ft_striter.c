#include <stdio.h>
#include <string.h>
#include "libft.h"

void	print(char *s)
{
	printf("%s\n", s);
}

int		main(void)
{
	ft_striter("hello world", print);
	return (0);
}