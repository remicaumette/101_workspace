#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *arr;
	int i;

	if (min >= max || (arr = (int *)malloc(sizeof(*arr) * (max - min))) == NULL)
		return (NULL);
	i = -1;
	while (++i < max - min)
		arr[i] = min + i;
	return (arr);
}
