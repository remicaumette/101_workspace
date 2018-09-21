#include "ft_std.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s1;
	const char	*s2;
	size_t		curr;

	s1 = dst;
	s2 = src;
	curr = 0;
	while (curr < len)
		s1[curr++] = *s2++;
	return (dst);
}