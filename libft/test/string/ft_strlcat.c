#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s1 = ft_strnew(5);
	strcpy(s1, "lol");

	printf("=== strlcat\n");
	printf("%s\n", s1);
	printf("%lu\n", strlcat(s1, "hello", 3));
	printf("%s\n", s1);

	char *s2 = ft_strnew(5);
	strcpy(s2, "lol");

	printf("=== strlcat\n");
	printf("%s\n", s2);
	printf("%lu\n", ft_strlcat(s2, "hello", 3));
	printf("%s\n", s2);
	return (0);
}
