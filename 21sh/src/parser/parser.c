/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 16:57:40 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 05:28:04 by rcaumett    ###    #+. /#+    ###.fr     */
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
	return (parser);
}

void		parser_cleanup(t_parser *parser)
{
	if (parser)
	{
		if (parser->root)
			node_destroy(parser->root);
		parser->root = NULL;
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
	(void)parser;
	return (0);
}
