#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(-10));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(10));
	printf("%s\n", ft_itoa(0));
	return (0);
}