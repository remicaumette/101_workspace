/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stack_size.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:45:37 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 18:10:22 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_stack_size(t_stack *stack)
{
	int i;

	i = 0;
	while (stack && ++i)
		stack = stack->next;
	return (i);
}
