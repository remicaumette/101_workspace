#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = ft_strnew(3);
	strcpy(s, "lol");
	printf("%s\n", s);
	ft_strdel(&s);
	printf("%s\n", s);
	return (0);
}
