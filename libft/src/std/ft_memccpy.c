#include "ft_std.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	s1 = dst;
	s2 = src;
	i = 0;
	while (s2[i] != c && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (i == n ? NULL : (dst + i));
}