#include "ft_std.h"

void *ft_memalloc(size_t size)
{
	void *mem;

	if ((mem = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}