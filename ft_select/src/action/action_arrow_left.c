/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_left.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:10:39 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 17:45:12 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

int	action_arrow_left(t_select *select)
{
	if ((select->x - 1) < 0)
		select->x = (select->window.ws_col / (select->max_length + 6)) - 1;
	else
		select->x--;
	ft_putstr(tgoto(tgetstr("cm", NULL), select->x * (select->max_length + 6) + 1, select->y));
	return (0);
}
