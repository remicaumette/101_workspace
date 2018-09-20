#include "ft_type.h"
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	for (int i = 0; i <= 127; i++)
		if (isascii(i) != ft_isascii(i))
		{
			printf("failed with '%c'\nexpected: %d\nreturned: %d\n", i, isascii(i), ft_isascii(i));
			return (1);
		}
	printf("ok!\n");
	return (0);
}