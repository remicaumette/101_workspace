#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[11];
	char s2[11];
	strcpy(s1, "despacito");
	strcpy(s2, "despacito");
	printf("%zu %lu\n", ft_strlcat(s1, "2", 11), strlcat(s2, "2", 11));
	printf("%s %s\n", s1, s2);

	for (int i = 0; i <= 10; i++)
		printf("%zu %lu\n", ft_strlcat(s1, "2", i), strlcat(s2, "2", i));
	return (strncmp(s1, s2, 11));
}