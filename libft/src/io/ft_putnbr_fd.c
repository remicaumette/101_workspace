/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:34:36 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 15:05:39 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	size;

	size = n < 0 ? 2 : 1;
	while ((n >= 10 || n <= -10) && ++size)
		n /= 10;
	return (size);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		curr;
	int		size;
	char	s[get_size(n) + 1];

	curr = n;
	size = get_size(n);
	s[size] = 0;
	while (size-- >= (curr < 0))
	{
		s[size] = (curr < 0 ? -(curr % 10) : (curr % 10)) + '0';
		curr /= 10;
	}
	if (n < 0)
		s[0] = '-';
	ft_putstr_fd(s, fd);
}
