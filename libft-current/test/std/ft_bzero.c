#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char *s1 = ft_strdup("helloworld");
	char *s2 = ft_strdup("helloworld");
	ft_bzero(s1, 5);
	bzero(s2, 5);
	return (!!memcmp(s1, s2, 11));
}