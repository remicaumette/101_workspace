#include "ft_std.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				curr;

	str1 = s1;
	str2 = s2;
	curr = 0;
	while (*str1 == *str2 && curr < n)
		str1++ && str2++ && curr++;
	return (*str1 - *str2);
}