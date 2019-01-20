/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   select_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 19:47:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 19:28:36 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

int	select_init(t_select *select, char **args)
{
	int				i;
	int				len;
	t_select_entry	*prev;
	t_select_entry	*curr;

	i = 0;
	prev = NULL;
	select->x = 0;
	select->y = 0;
	select->max_length = 0;
	select->status = -1;
	while (args[++i])
	{
		if (!(curr = select_entry_create(args[i])))
			return (1);
		if (prev)
			prev->next = curr;
		else
			select->entry = curr;
		if ((len = ft_strlen(args[i])) > select->max_length)
			select->max_length = len;
		prev = curr;
	}
	select->count = i - 1;
	return (0);
}
