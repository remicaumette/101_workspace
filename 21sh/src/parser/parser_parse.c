/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_parse.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:12:30 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:12:38 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	parser_parse(t_parser *parser)
{
	t_command	*cmd;
	t_token		*curr;
	t_node		*node;

	parser->curr = parser->shell->lexer->begin;
	while (parser->curr)
	{
		cmd = NULL;
		curr = parser->curr;
		if (curr->type == T_WORD && !(cmd = command_parse(parser)))
			return (1);
		if (!(node = node_create(curr->type, cmd)))
			return (1);
		node_insert(&parser->root, node);
		parser->curr = curr->type == T_WORD ? parser->curr : curr->next;
	}
	return (0);
}
