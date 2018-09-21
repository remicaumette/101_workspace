#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char *s1 = strdup("helloworld");
	ft_strclr(s1);
	for (int i = 0; i < 11; i++)
		if (s1[i] != 0)
			return (1);
	return (0);
}