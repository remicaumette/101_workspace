#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*s;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if ((s = (char *) malloc(sizeof(*s) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*src)
		s[i++] = *src++;
	s[i] = 0;
	return (s);
}
