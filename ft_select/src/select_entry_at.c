/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   select_entry_at.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:19:25 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 19:20:52 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

t_select_entry	*select_entry_at(t_select *select, int x, int y)
{
	int				i;
	t_select_entry	*entry;

	if (x < 0 ||
		y < 0 ||
		(x >= (select->window.ws_col / (select->max_length + 6))) ||
		(y * (select->window.ws_col / (select->max_length + 6)) + x)
			> select->count)
		return (NULL);
	i = 0;
	entry = select->entry;
	while (++i < (x + (y * (select->window.ws_col / (select->max_length + 6)))
		+ 1) && entry)
		if (!(entry = entry->next))
			return (NULL);
	return (entry);
}
