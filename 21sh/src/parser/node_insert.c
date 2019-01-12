/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   node_insert.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:11:41 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:11:46 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

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
