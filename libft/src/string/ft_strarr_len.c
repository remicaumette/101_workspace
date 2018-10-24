#include "libft.h"

int	ft_strarr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr && arr[len])
		len++;
	return (len);
}
