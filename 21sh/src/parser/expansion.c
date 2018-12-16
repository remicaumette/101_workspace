/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expansion.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 18:27:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 05:37:30 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static char		*ft_strjoinc(char **word, char c)
{
	char	*tmp;
	char	m[2];

	m[0] = c;
	m[1] = 0;
	if (!(tmp = ft_strjoin(*word, m)))
		return (NULL);
	ft_strdel(word);
	return (*word = tmp);
}

char			*parser_expandword(t_parser *parser, t_token *token)
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
