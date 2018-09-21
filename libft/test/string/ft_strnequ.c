#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	return (!(ft_strnequ("ok", "ok", 2) && ft_strnequ("ok", "oke", 2) && !ft_strnequ("ok", "oke", 3)));
}
