#include "ft_string.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t size;

	size = 0;
	while (size < n)
		if (*s1 == *s2)
			s1++ && s2++ && size++;
		else
			return (*s1 - *s2);
	return (0);
}