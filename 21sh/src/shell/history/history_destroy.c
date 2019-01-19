/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_destroy.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 14:53:07 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 14:17:30 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	history_destroy(t_history *history)
{
	t_histentry	*curr;
	t_histentry	*next;
	int			i;

	if (history)
	{
		i = 0;
		next = history->begin;
		while (next)
		{
			curr = next;
			next = history->size != ++i ? curr->next : NULL;
			histentry_destroy(curr);
		}
		ft_memdel((void **)&history);
	}
}
