#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("returned: %d expected: %d\n", ft_strncmp("ab", "ac", 1), strncmp("ab", "ac", 1));
	printf("returned: %d expected: %d\n", ft_strncmp("ab", "ab", 1), strncmp("ab", "ab", 1));
	printf("returned: %d expected: %d\n", ft_strncmp("ab", "aa", 1), strncmp("ab", "aa", 1));
	printf("returned: %d expected: %d\n", ft_strncmp("ab", "aa", 2), strncmp("ab", "aa", 2));
	printf("returned: %d expected: %d\n", ft_strncmp("a", "a", 3), strncmp("a", "a", 3));
	return (0);
}
