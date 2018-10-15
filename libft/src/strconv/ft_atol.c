/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 15:06:50 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 15:06:51 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *s)
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
		r = r * 10 + (*s++ - '0');
	return (n ? -r : r);
}
