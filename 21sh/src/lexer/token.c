/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:30:12 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 02:36:32 by rcaumett    ###    #+. /#+    ###.fr     */
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

static char		*lexer_addwordtoken(t_lexer *lexer, char *str)
{
	char	*tmp;
	t_token	*token;

	tmp = str - 1;
	if (lexer->quote && lexer->end && lexer->end->type == T_WORD)
		token = lexer->end;
	else if (!(token = lexer_addtoken(lexer, T_WORD, NULL)))
		return (NULL);
	while (*++tmp && !((*tmp == '\t' || *tmp == ' ' ||
		lexer_gettype(tmp) != T_WORD) && lexer->quote == -1))
	{
		if ((*tmp == '\'' || *tmp == '"') && lexer->quote == -1)
			lexer->quote = *tmp;
		else if (*tmp == lexer->quote)
			lexer->quote = -1;
		if (!(ft_strjoinc(&token->content, *tmp)))
			return (NULL);
	}
	tmp -= (token->content != NULL);
	return (tmp);
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
		else if (type != T_WORD &&
			!(tmp = lexer_addsimpletoken(lexer, type, tmp)))
			return (1);
	}
	return (0);
}
