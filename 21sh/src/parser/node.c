/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   node.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 21:59:45 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 16:34:35 by rcaumett    ###    #+. /#+    ###.fr     */
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

void	node_insert(t_node **root, t_node *node)
{
	t_node	*curr;

	if (*root)
	{
		curr = *root;
		while (curr->next)
			curr = curr->next;
		curr->next = node;
	}
	else
		*root = node;
}
