#include "libft.h"

char	**ft_strarr_add(char **arr, char *elem)
{
	char	**tmp;
	int		len;
	int		i;

	len = 0;
	while (arr && arr[len])
		len++;
	if (!(tmp = ft_memalloc(sizeof(*tmp) * (len + 2))))
		return (NULL);
	i = -1;
	while (++i < len)
		tmp[i] = arr[i];
	tmp[i++] = ft_strdup(elem);
	tmp[i] = NULL;
	ft_memdel((void **)&arr);
	return (tmp);
}
