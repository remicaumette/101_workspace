#include <stdio.h>
#include <string.h>
#include "libft.h"

char	map(char c)
{
	return (c);
}

int		main(void)
{
	printf("%s\n", ft_strmap("hello", map));
	return (0);
}