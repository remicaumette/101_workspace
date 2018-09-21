#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	void *s1 = malloc(5);
	ft_memdel(&s1);
	return (s1 != NULL);
}