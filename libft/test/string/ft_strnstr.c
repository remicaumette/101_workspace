#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("returned: %s expected: %s\n", ft_strnstr("abcdef", "cd", 7), strnstr("abcdef", "cd", 7));
	printf("returned: %s expected: %s\n", ft_strnstr("abcdef", "cd", 2), strnstr("abcdef", "cd", 2));
	printf("returned: %s expected: %s\n", ft_strnstr("abcdef", "cd", 3), strnstr("abcdef", "cd", 3));
	printf("returned: %s expected: %s\n", ft_strnstr("abcdef", "", 7), strnstr("abcdef", "", 7));
	printf("returned: %s expected: %s\n", ft_strnstr("abcdef", "aa", 7), strnstr("abcdef", "aa", 7));
	return (0);
}
