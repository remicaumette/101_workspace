/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_down.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:10:39 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 19:19:56 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

int	action_arrow_down(t_select *select)
{
	if (select_entry_at(select, select->x, select->y + 1))
		select->y++;
	ft_putstr(tgoto(tgetstr("cm", NULL),
		select->x * (select->max_length + 6) + 1, select->y));
	return (0);
}
