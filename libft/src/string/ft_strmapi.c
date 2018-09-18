#include "ft_string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if ((tmp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (*s)
		*tmp++ = f(*s++, i++);
	return (tmp);
}