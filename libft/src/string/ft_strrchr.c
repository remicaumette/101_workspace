#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*str;

	ptr = NULL;
	str = (char *) s;
	while (*str)
		if (*str == c)
			ptr = str;
		else
			str++;
	return (*str == c ? str : ptr);
}