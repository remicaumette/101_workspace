#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("returned: %d expected: %d\n", ft_strcmp("ab", "ac"), strcmp("ab", "ac"));
	printf("returned: %d expected: %d\n", ft_strcmp("ab", "ab"), strcmp("ab", "ab"));
	printf("returned: %d expected: %d\n", ft_strcmp("ab", "aa"), strcmp("ab", "aa"));
}
