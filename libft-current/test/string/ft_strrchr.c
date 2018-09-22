#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("returned: %s expected: %s\n", ft_strrchr("aba", 'a'), strrchr("aba", 'a'));
	printf("returned: %s expected: %s\n", ft_strrchr("aba", 'b'), strrchr("aba", 'b'));
	printf("returned: %s expected: %s\n", ft_strrchr("aba", 'c'), strrchr("aba", 'c'));
	printf("returned: %s expected: %s\n", ft_strrchr("aba", '\0'), strrchr("aba", '\0'));
	return (0);
}
