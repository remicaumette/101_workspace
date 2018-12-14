/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:30:12 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 15:23:52 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			lexer_tokenlen(t_token *token)
{
	if (token->content && token->type == WORD)
		return (ft_strlen(token->content) - 1);
	if (token->type == OPERATOR)
		return (token->op == DLESSDASH ? 2 : 1);
	return (0);
}

int			lexer_tokenize(t_lexer *lexer, char *str)
{
	t_token			*curr;
	t_tokentype		type;
	t_operatortype	op;
	char			*tmp;
	char			*word;

	word = NULL;
	tmp = str - 1;
	while (*++tmp)
	{
		if (*tmp == ' ' || *tmp == '\t')
			continue ;
		if ((op = lexer_getop(tmp)))
			type = OPERATOR;
		else
			type = (*tmp == '\n' || *tmp == ';') ? NEWLINE : WORD;
		if (type == WORD)
			tmp += lexer_getword(tmp, &word) - 1;
		else if (type == OPERATOR)
			tmp += 1 + op == DLESSDASH;
		if (!(curr = lexer_addtoken(lexer, type, op, word)))
			return (1);
		ft_strdel(&word);
	}
	return (0);
}
