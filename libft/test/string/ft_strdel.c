#include "libft.h"
#include <stdio.h>

int main(void)
{
	char *s = ft_strnew(3);
	s[0] = 'l';
	s[1] = 'o';
	s[2] = 'l';
	
	printf("%s\n", s);
	ft_strdel(&s);
	printf("%s\n", s);
}
