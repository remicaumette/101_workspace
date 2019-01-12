/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 10:03:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:07:34 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_tokeninfo	g_tokens[] = {
	{"<<-", T_DLESSDASH, 3},
	{"&&", T_ANDIF, 2},
	{"||", T_ORIF, 2},
	{";;", T_DSEMI, 2},
	{"<<", T_DLESS, 2},
	{">>", T_DGREAT, 2},
	{"<&", T_LESSAND, 2},
	{">&", T_GREATAND, 2},
	{"<>", T_LESSGREAT, 2},
	{">|", T_CLOBBER, 2},
	{"|", T_PIPE, 1},
	{";", T_NEWLINE, 1},
	{"\n", T_NEWLINE, 1},
};

t_tokentype	lexer_gettype(char *str)
{
	int	i;

	i = -1;
	while (++i < 13)
		if (ft_strnequ(str, g_tokens[i].format, g_tokens[i].len))
			return (g_tokens[i].type);
	return (T_WORD);
}

char		lexer_getmissingtoken(t_lexer *lexer)
{
	t_token	*curr;
	t_token	*last;

	if (lexer->quote != -1)
		return (lexer->quote);
	curr = lexer->begin;
	last = NULL;
	while (curr)
	{
		if (curr->type != T_NEWLINE)
			last = curr;
		curr = curr->next;
	}
	if (last && last->type == T_PIPE)
		return ('|');
	return (-1);
}
