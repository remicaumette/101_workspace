#include "ft_string.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (*src && i < len)
		dst[i++] = *src++;
	while (i < len + 1)
		dst[i++] = 0;
	return (dst);
}