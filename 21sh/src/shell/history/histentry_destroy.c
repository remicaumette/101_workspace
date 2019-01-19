/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   histentry_destroy.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 15:37:04 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 15:49:49 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	histentry_destroy(t_histentry *entry)
{
	if (entry)
	{
		if (entry->content)
			ft_strdel(&entry->content);
		ft_memdel((void **)&entry);
	}
}
