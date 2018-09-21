#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[11];
	char s2[11];
	strcpy(s1, "despacito");
	strcpy(s2, "despacito");
	ft_strcat(s1, "2");
	strcat(s2, "2");
	printf("%s %s\n", s1, s2);
	return (strncmp(s1, s2, 11));
}