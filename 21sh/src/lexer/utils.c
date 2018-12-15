/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 10:03:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 21:38:02 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_tokentype	lexer_gettype(char *str)
{
	int	i;

	i = -1;
	while (++i < 15)
		if (ft_strnequ(str, g_tokens[i].format, g_tokens[i].len))
			return (g_tokens[i].type);
	return (T_WORD);
}

int			lexer_isok(t_lexer *lexer)
{
	t_token	*curr;
	t_token	*last;

	if (lexer->quote != -1)
		return (lexer->quote == '"' ? T_DQUOTE : T_SQUOTE);
	curr = lexer->begin;
	last = NULL;
	while (curr)
	{
		if (curr->type != T_NEWLINE)
			last = curr;
		curr = curr->next;
	}
	if (last && last->type == T_PIPE)
		return (T_PIPE);
	return (-1);
}
