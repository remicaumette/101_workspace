#include <stdio.h>
#include <string.h>
#include "libft.h"

void	check_mem(void *returned, void *expected, int n)
{
	if (memcmp(returned, expected, n))
	{
		printf("returned: '%s' expected: '%s'\n", (unsigned char *)returned, (unsigned char *)expected);
		exit(1);
	}
}

int	main(void)
{
	char *s1 = ft_strdup("helloworld");
	char *s2 = ft_strdup("helloworld");
	printf("%s = %s\n", ft_memccpy(s1, "despacito 2", ' ', 9), memccpy(s2, "despacito 2", ' ', 9));
	check_mem(s1, s2, 11);

	char *s3 = ft_strdup("helloworld123");
	char *s4 = ft_strdup("helloworld123");
	printf("%s = %s\n", ft_memccpy(s3, "despacito 2", ' ', 14), memccpy(s4, "despacito 2", ' ', 14));
	check_mem(s3, s4, 11);

	return (0);
}