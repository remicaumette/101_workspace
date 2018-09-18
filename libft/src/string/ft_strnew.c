#include "ft_string.h"

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(sizeof(char) * (size + 1)));
}