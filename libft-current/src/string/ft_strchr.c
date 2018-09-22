#include "ft_string.h"

char	*ft_strchr(const char *s, int c)
{
	s--;
	while (*++s)
		if (*s == c)
			return ((char *) s);
	return (*s == c ? (char *) s : NULL);
}