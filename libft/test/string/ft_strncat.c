#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[11];
	char s2[11];
	strcpy(s1, "despacito");
	strcpy(s2, "despacito");
	ft_strncat(s1, "23", 1);
	strncat(s2, "23", 1);
	return (strncmp(s1, s2, 11));
}