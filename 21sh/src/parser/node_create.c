/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   node_create.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:11:22 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:11:24 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_node	*node_create(t_tokentype type, t_command *command)
{
	t_node	*node;

	if (!(node = ft_memalloc(sizeof(t_node))))
		return (NULL);
	node->type = type;
	node->command = command;
	node->next = NULL;
	return (node);
}
