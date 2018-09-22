#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;
	int		curr;

	length = ft_strlen(s);
	curr = length + 1;
	while (curr--)
		if (s[curr] == c)
			return ((char *) s + curr);
	return (NULL);
}