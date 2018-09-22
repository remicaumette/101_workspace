#include "ft_std.h"

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}