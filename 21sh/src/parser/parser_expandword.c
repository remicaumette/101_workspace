/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_expandword.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:10:52 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:10:54 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char	*parser_expandword(t_parser *parser, t_token *token)
{
	char	*word;
	char	*tmp;

	(void)parser;
	word = NULL;
	tmp = token->content - 1;
	while (*++tmp)
	{
		(void)ft_strjoinc;
	}
	return (tmp);
}
