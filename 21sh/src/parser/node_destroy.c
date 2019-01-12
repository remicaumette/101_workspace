/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   node_destroy.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:11:30 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:11:36 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	node_destroy(t_node *node)
{
	if (node)
	{
		if (node->command)
			command_destroy(node->command);
		if (node->next)
			node_destroy(node->next);
		ft_memdel((void **)&node);
	}
}
