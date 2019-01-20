/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   select_render.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 15:30:51 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 16:12:22 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

int	select_render(t_select *select)
{
	int				x;
	int				y;
	t_select_entry	*entry;

	x = -1;
	y = 0;
	entry = select->entry;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &select->window);
	ft_putstr(tgetstr("cl", NULL));
	while (++x < (select->window.ws_col / (select->max_length + 6)) && entry)
	{
		ft_putstr(tgoto(tgetstr("cm", NULL), x * (select->max_length + 6), y));
		ft_putstr(entry->selected ? "[x] " : "[ ] ");
		ft_putstr(entry->content);
		entry = entry->next;
	}
	return (0);
}
