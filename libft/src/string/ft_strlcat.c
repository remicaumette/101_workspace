#include "ft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	offset;
	char	*ptr;

	offset = ft_strlen(dst);
	if (dstsize <= offset + ft_strlen(src))
		return (dstsize + 1);
	ptr = dst;
	while (*src)
		*(ptr++ + offset) = *src++;
	return (ft_strlen(dst));
}