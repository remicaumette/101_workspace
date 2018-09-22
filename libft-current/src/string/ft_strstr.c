#include "ft_string.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int length;

	length = ft_strlen(s2);
	s1--;
	while (*++s1)
	{
		i = -1;
		while (s2[++i])
			if (s2[i] != *(s1 + i))
				break ;
		if (i == length)
			return ((char *) s1);
	}
	return (NULL);
}