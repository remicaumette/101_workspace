#include "ft_string.h"

char	*ft_strdup(const char *s1)
{
	char *tmp;

	if ((tmp = ft_strnew(ft_strlen(s1))) == NULL)
		return (NULL);
	return (ft_strcpy(tmp, s1));
}