/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stack_destroy.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:45:34 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:48:05 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_destroy(t_stack **begin, void (*del)(void *))
{
	while (*begin)
		del(ft_stack_pop(begin));
}
