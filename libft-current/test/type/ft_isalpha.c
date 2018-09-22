#include "ft_type.h"
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	for (int i = 0; i <= 127; i++)
		if (isalpha(i) != ft_isalpha(i))
		{
			printf("failed with '%c'\nexpected: %d\nreturned: %d\n", i, isalpha(i), ft_isalpha(i));
			return (1);
		}
	printf("ok!\n");
	return (0);
}