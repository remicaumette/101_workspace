#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("returned: %s expected: %s\n", ft_strchr("ab", 'a'), strchr("ab", 'a'));
	printf("returned: %s expected: %s\n", ft_strchr("ab", 'b'), strchr("ab", 'b'));
	printf("returned: %s expected: %s\n", ft_strchr("ab", 'c'), strchr("ab", 'c'));
	printf("returned: %s expected: %s\n", ft_strchr("ab", '\0'), strchr("ab", '\0'));
	return (0);
}
