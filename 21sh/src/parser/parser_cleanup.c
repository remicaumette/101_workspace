/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_cleanup.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:13:05 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:13:06 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	parser_cleanup(t_parser *parser)
{
	if (parser)
	{
		if (parser->root)
			node_destroy(parser->root);
		parser->root = NULL;
		parser->curr = NULL;
	}
}
