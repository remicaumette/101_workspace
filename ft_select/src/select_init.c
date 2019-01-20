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

static int	update_window_size(t_select *select)
{
	return (ioctl(STDOUT_FILENO, TIOCGWINSZ, &select->window) == -1);
}

int			select_init(t_select *select, char **args)
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
	signal(SIGWINCH, update_window_size);
	return (update_window_size(select) == -1);
}
