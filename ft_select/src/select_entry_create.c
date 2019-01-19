/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   select_entry_create.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 19:52:36 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 19:56:25 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

t_select_entry	*select_entry_create(char *content)
{
	t_select_entry	*entry;

	if (!(entry = ft_memalloc(sizeof(t_select_entry))) ||
		!(entry->content = ft_strdup(content)))
		return (NULL);
	entry->selected = 0;
	entry->next = NULL;
	return (entry);
}
