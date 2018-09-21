#include "ft_string.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *) s;
	while (*str)
		if (*str == c)
			return (str);
		else
			str++;
	return (*str == c ? str : NULL);
}