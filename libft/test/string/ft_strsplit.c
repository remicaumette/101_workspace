#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char **v = ft_strsplit("*salut*les***etudiants*", '*');
	while (*v)
		printf("%s\n", *v++);
	return (0);
}