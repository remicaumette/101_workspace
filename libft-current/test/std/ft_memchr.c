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
	printf("%s = %s\n", ft_memchr(s1, 'o', 11), memchr(s2, 'o', 11));
	printf("%s = %s\n", ft_memchr(s1, 'a', 11), memchr(s2, 'a', 11));
	return (0);
}