/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_insert.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 15:29:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 13:16:22 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_histentry	*history_insert(t_history *history, char *content)
{
	t_histentry	*entry;

	if (!(entry = histentry_create(content)))
		return (NULL);
	entry->next = history->begin;
	entry->prev = history->end;
	history->size++;
	history->begin = entry;
	if (history->end)
		history->end->next = entry;
	else
		history->end = entry;
	return (entry);
}
