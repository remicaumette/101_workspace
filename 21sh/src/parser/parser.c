/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 16:57:40 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 16:34:45 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_parser	*parser_create(t_shell *shell)
{
	t_parser	*parser;

	if (!(parser = ft_memalloc(sizeof(t_parser))))
		return (NULL);
	parser->shell = shell;
	parser->root = NULL;
	parser->curr = NULL;
	return (parser);
}

void		parser_cleanup(t_parser *parser)
{
	if (parser)
	{
		if (parser->root)
			node_destroy(parser->root);
		parser->root = NULL;
		parser->curr = NULL;
	}
}

void		parser_destroy(t_parser *parser)
{
	if (parser)
	{
		parser_cleanup(parser);
		ft_memdel((void **)&parser);
	}
}

int			parser_parse(t_parser *parser)
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
