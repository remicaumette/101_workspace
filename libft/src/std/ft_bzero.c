#include "ft_std.h"

void	ft_bzero(void *mem, size_t size)
{
	unsigned char *str;

	str = mem;
	while (size--)
		*str++ = 0;
}