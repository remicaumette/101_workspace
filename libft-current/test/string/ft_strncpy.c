#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[11];
	char s2[11];
	ft_strncpy(s1, "despacito 2", 4);
	strncpy(s2, "despacito 2", 4);
	printf("%s %s\n", s1, s2);
	return (strncmp(s1, s2, 11));
}