/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stack_push.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:45:50 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 18:10:05 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stack_push(t_stack **begin, void *content)
{
	t_stack *stack;

	if ((stack = (t_stack *)ft_memalloc(sizeof(stack))) == NULL)
		return (NULL);
	stack->content = content;
	stack->next = *begin;
	return (*begin = stack);
}
