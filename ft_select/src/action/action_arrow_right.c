/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_right.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:10:39 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 17:43:58 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

int	action_arrow_right(t_select *select)
{
	if ((select->x + 1) < (select->window.ws_col / (select->max_length + 6)))
		select->x++;
	else
		select->x = 0;
	ft_putstr(tgoto(tgetstr("cm", NULL), select->x * (select->max_length + 6) + 1, select->y));
	return (0);
}
