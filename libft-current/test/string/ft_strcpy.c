#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[11];
	char s2[11];
	ft_strcpy(s1, "despacito2");
	strcpy(s2, "despacito2");
	return (strncmp(s1, s2, 11));
}