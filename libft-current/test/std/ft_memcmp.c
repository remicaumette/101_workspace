#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	printf("%d = %d\n", ft_memcmp("helloworld", "helloworld", 11), memcmp("helloworld", "helloworld", 11));
	printf("%d = %d\n", ft_memcmp("helloworld", "hellaworld", 4), memcmp("helloworld", "hellaworld", 4));
	printf("%d = %d\n", ft_memcmp("helloworld", "hellaworld", 6), memcmp("helloworld", "hellaworld", 6));
	printf("%d = %d\n", ft_memcmp("hellaworld", "helloworld", 6), memcmp("hellaworld", "helloworld", 6));
	return (0);
}