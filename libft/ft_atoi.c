/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:35:00 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 16:55:49 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	long	r;
	int		n;

	r = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	n = *s == '-';
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + (*s++ - '0');
	}
	return (n ? -r : r);
}