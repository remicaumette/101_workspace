#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("returned: %s expected: %s\n", ft_strstr("abcdef", "cd"), strstr("abcdef", "cd"));
	printf("returned: %s expected: %s\n", ft_strstr("abcdef", ""), strstr("abcdef", ""));
	printf("returned: %s expected: %s\n", ft_strstr("abcdef", "aa"), strstr("abcdef", "aa"));
	return (0);
}
