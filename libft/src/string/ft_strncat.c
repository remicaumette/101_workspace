#include "ft_string.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s1;
	i = 0;
	while (*s1)
		s1++;
	while (i < n)
		*s1++ = s2[i++];
	*s1 = 0;
	return (ptr);
}