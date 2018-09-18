#include "ft_string.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *tmp;

	if ((tmp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (*s)
		*tmp++ = f(*s++);
	return (tmp);
}