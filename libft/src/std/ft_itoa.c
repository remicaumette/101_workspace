#include "ft_string.h"

char	*ft_itoa(int n)
{
	int		curr;
	int		size;
	char	*s;

	curr = n;	
	size = n < 0 ? 2 : 1;
	while ((curr >= 10 || curr <= -10) && ++size)
		curr /= 10;
	if ((s = ft_strnew(size)) == NULL)
		return (NULL);
	curr = n;
	while (size-- >= (curr < 0))
	{
		s[size] = (curr < 0 ? -(curr % 10) : (curr % 10)) + '0';
		curr /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}