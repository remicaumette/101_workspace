#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char *s1 = ft_strdup("helloworld");
	char *s2 = ft_strdup("helloworld");
	ft_memset(s1, 'x', 3);
	memset(s2, 'x', 3);
	return (!!memcmp(s1, s2, 11));
}