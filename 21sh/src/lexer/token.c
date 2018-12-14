/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:30:12 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 16:23:05 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static char		*lexer_addsimpletoken(t_lexer *lexer, t_tokentype type,
	char *str)
{
	t_operatortype	op;

	if (type == NEWLINE && !(lexer_addtoken(lexer, NEWLINE, NONE, NULL)))
		return (NULL);
	else if (type == OPERATOR)
	{
		op = lexer_getop(str);
		if (!(lexer_addtoken(lexer, OPERATOR, op, NULL)))
			return (NULL);
		return (str + 1 - (op == PIPE) + (op == DLESSDASH));
	}
	return (str);
}

static char		*lexer_addwordtoken(t_lexer *lexer, char *str)
{
	char	*tmp;
	char	*word;
	char	quote;

	tmp = str - 1;
	word = NULL;
	quote = -1;
	while (*++tmp)
	{
		if ((*tmp == '\t' || *tmp == ' ') && quote == -1)
			break ;
		else if ((*tmp == '\'' || *tmp == '"') && quote == -1)
			quote = *tmp;
		else if (quote != -1 && *tmp == quote)
			quote = -1;
		else if (!(ft_strjoinc(&word, *tmp)))
			return (0);
	}
	if (!(lexer_addtoken(lexer, WORD, NONE, word)))
		return (NULL);
	return (tmp - 1);
}

int				lexer_tokenize(t_lexer *lexer, char *str)
{
	t_tokentype	type;
	char		*tmp;

	tmp = str - 1;
	while (*++tmp)
	{
		if (*tmp == ' ' || *tmp == '\t')
			continue ;
		type = lexer_gettype(tmp);
		if ((type == OPERATOR || type == NEWLINE) &&
			!(tmp = lexer_addsimpletoken(lexer, type, tmp)))
			return (1);
		if (type == WORD && !(tmp = lexer_addwordtoken(lexer, tmp)))
			return (1);
	}
	return (0);
}
