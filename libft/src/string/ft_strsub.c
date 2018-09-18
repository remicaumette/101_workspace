#include "ft_string.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	if ((tmp = ft_strnew(len)) == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = s[start + i];
		i++;
	}
	return (tmp);
}