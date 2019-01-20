/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_espace.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:10:39 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 19:20:11 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

int	action_espace(t_select *select)
{
	t_select_entry	*entry;

	if ((entry = select_entry_at(select, select->x, select->y)))
	{
		entry->selected = !entry->selected;
		if (entry->selected)
			ft_putstr("x");
		else
			ft_putstr("x");
		ft_putstr(tgoto(tgetstr("cm", NULL),
			select->x * (select->max_length + 6) + 1, select->y));
	}
	return (0);
}
