/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_up.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:10:39 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 17:51:25 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

int	action_arrow_up(t_select *select)
{
	if (select->y - 1 < 0)
		select->y = select->count / (select->window.ws_col / (select->max_length + 6));
	else
		select->y--;
	ft_putstr(tgoto(tgetstr("cm", NULL), select->x * (select->max_length + 6) + 1, select->y));
	return (0);
}
