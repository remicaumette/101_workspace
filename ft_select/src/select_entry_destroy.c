/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   select_entry_destroy.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 19:55:19 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 19:57:37 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

void	select_entry_destroy(t_select_entry *entry)
{
	if (entry)
	{
		if (entry->content)
			ft_strdel(&entry->content);
		ft_memdel((void **)&entry);
	}
}
