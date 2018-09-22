#include "ft_std.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = dst;
	s2 = src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i++] == (unsigned char) c)
			break;
	}
	return (i == n ? NULL : (dst + i));
}