/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_create.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 14:42:05 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 16:00:32 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_history	*history_create(void)
{
	t_history	*history;

	if (!(history = ft_memalloc(sizeof(t_history))))
		return (NULL);
	history->size = 0;
	history->begin = NULL;
	history->curr = NULL;
	history->end = NULL;
	return (history);
}
