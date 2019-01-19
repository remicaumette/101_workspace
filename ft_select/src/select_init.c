/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   select_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 19:47:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 20:01:45 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

int	select_init(t_select *select, char **args)
{
	int				i;
	t_select_entry	*prev;
	t_select_entry	*curr;

	i = 0;
	prev = NULL;
	while (args[++i])
	{
		if (!(curr = select_entry_create(args[i])))
			return (1);
		if (prev)
			prev->next = curr;
		else
			select->entry = curr;
		prev = curr;
	}
	select->count = i - 1;
	return (0);
}
