#include "ft_type.h"
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	for (int i = 0; i <= 127; i++)
		if (isalnum(i) != ft_isalnum(i))
		{
			printf("failed with '%c'\nexpected: %d\nreturned: %d\n", i, isalnum(i), ft_isalnum(i));
			return (1);
		}
	printf("ok!\n");
	return (0);
}