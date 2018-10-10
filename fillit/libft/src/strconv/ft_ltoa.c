/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ltoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:03:51 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:03:53 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long n)
{
	long	curr;
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
