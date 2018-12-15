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
	t_tokeninfo	info;
	int			i;

	i = -1;
	while (++i < 15)
		if (g_tokens[i].type == type)
		{
			info = g_tokens[i];
			break ;
		}
	if (!(lexer_addtoken(lexer, type, NULL)))
		return (NULL);
	return (str + info.len - 1);
}

static char		*lexer_addwordtoken(t_lexer *lexer, char *str)
{
	char	*tmp;
	char	*word;
	char	quote;

	tmp = str - 1;
	word = NULL;
	if (lexer->end && (lexer->end->type == T_SQUOTE ||
		lexer->end->type == T_DQUOTE))
		quote = lexer->end->type == T_SQUOTE ? '\'' : '"';
	else
		quote = -1;
	while (*++tmp )
	{
		if (((*tmp == '\t' || *tmp == ' ' || lexer_gettype(tmp) != T_WORD) &&
			quote == -1) || (quote != -1 && quote == *tmp))
			break ;
		else if (!(ft_strjoinc(&word, *tmp)))
			return (0);
	}
	if (!(lexer_addtoken(lexer, T_WORD, word)))
		return (NULL);
	return (tmp - (word != NULL));
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
		if (type == T_WORD && !(tmp = lexer_addwordtoken(lexer, tmp)))
			return (1);
		else if (type != T_WORD && !(tmp = lexer_addsimpletoken(lexer, type, tmp)))
			return (1);
	}
	return (0);
}
