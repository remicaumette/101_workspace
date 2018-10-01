#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char **v = ft_strsplit("                       w", ' ');
	while (*v)
		printf("%s\n", *v++);
	return (0);
}