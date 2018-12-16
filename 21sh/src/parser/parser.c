/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 16:57:40 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 02:36:11 by rcaumett    ###    #+. /#+    ###.fr     */
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
	return (parser);
}

void		parser_destroy(t_parser *parser)
{
	if (parser)
	{
		ft_memdel((void **)&parser);
	}
}
