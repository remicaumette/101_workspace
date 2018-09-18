#include "ft_std.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	s1 = dst;
	s2 = src;
	i = -1;
	while (++i < n)
		s1[i] = s2[i];
	return (dst);
}