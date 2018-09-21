#include <stdio.h>
#include <string.h>
#include "libft.h"

char	print(unsigned int index, char c)
{
	c = '0';
	return (index + '0');
}

int		main(void)
{
	printf("%s\n", ft_strmapi("hello", print));
	return (0);
}