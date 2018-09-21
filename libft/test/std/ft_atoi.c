#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("		  -2147483648"));
	printf("%d\n", ft_atoi("	 	- 2147483648"));
	printf("%d\n", ft_atoi("-10"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("10"));
	printf("%d\n", ft_atoi("0"));
	return (0);
}