#include "ft_string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	if ((tmp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (*s && ++i)
		tmp[i - 1] = f(i - 1, *s++);
	return (tmp);
}