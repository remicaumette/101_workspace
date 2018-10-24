#include "libft.h"

void	ft_strarr_del(char **arr)
{
	int	i;

	i = -1;
	while (arr && arr[++i])
		ft_strdel(&arr[i]);
	ft_memdel((void **)&arr);
}
