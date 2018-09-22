#include "ft_std.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				curr;

	str1 = s1;
	str2 = s2;
	curr = 0;
	while (curr < n)
		if (*str1 == *str2)
			++str1 && ++str2 && ++curr;
		else
			return ((*str1 - *str2) < 0 ? -1 : 1);
	return (0);
}