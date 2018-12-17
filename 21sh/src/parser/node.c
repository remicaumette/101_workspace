/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   node.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 21:59:45 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 16:07:48 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_node	*node_create(t_tokentype type, t_command *command)
{
	t_node	*node;

	if (!(node = ft_memalloc(sizeof(t_node))))
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->type = type;
	node->command = command;
	return (node);
}

void	node_destroy(t_node *node)
{
	if (node)
	{
		if (node->left)
			node_destroy(node->left);
		if (node->right)
			node_destroy(node->right);
		if (node->command)
			command_destroy(node->command);
		ft_memdel((void **)&node);
	}
}

void	node_insert(t_node **root, t_node *node)
{

}
