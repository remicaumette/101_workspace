#include "ft_std.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			curr;

	str = (unsigned char *) s;
	curr = 0;
	while (str[curr] && curr < n)
		if (str[curr] == (unsigned char) c)
			return (str + curr);
		else
			curr++;
	return (NULL);
}