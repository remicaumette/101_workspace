/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stack_pop.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:45:54 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:55:21 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_stack_pop(t_stack **begin)
{
	t_stack	*stack;
	void	*content;

	if (!begin || !*begin)
		return (NULL);
	stack = *begin;
	*begin = (*begin)->next;
	content = stack->content;
	ft_memdel((void **)&stack);
	return (content);
}
