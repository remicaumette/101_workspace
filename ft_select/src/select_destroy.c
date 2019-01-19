/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   select_destroy.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 19:47:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 20:08:21 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

void	select_destroy(t_select *select)
{
	t_select_entry	*curr;
	t_select_entry	*next;

	next = select->entry;
	while (next)
	{
		curr = next;
		next = curr->next;
		select_entry_destroy(curr);
	}
}
