#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char *s1 = ft_memalloc(5);
	for (int i = 0; i < 5; i++)
		if (s1[i] != 0)
			return (1);
	free(s1);
	return (0);
}