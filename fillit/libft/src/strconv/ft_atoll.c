#include "libft.h"

long long	ft_atoll(const char *s)
{
	long long	r;
	int			n;

	r = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	n = *s == '-';
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
		r = r * 10 + (*s++ - '0');
	return (n ? -r : r);
}
