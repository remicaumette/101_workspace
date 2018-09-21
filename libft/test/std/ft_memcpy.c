#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char *s1 = ft_strdup("helloworld");
	char *s2 = ft_strdup("helloworld");
	ft_memcpy(s1, "despacito 2", 9);
	memcpy(s2, "despacito 2", 9);
	return (!!memcmp(s1, s2, 11));
}