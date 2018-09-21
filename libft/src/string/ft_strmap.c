#include "ft_string.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	if ((tmp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (*s)
		tmp[i++] = f(*s++);
	return (tmp);
}