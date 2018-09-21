#include "ft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}