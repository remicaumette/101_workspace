/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:30:12 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 14:48:18 by rcaumett    ###    #+. /#+    ###.fr     */
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
	t_token	*token;
	char	*word;
	char	*join;

	tmp = str - 1;
	if (lexer->quote != -1 && lexer->end && lexer->end->type == T_WORD)
		token = lexer->end;
	else if (!(token = lexer_addtoken(lexer, T_WORD, NULL)))
		return (NULL);
	while (*++tmp && !((*tmp == '\t' || *tmp == ' ' ||
		lexer_gettype(tmp) != T_WORD) && lexer->quote == -1))
		if ((*tmp == '\'' || *tmp == '"') && lexer->quote == -1)
			lexer->quote = *tmp;
		else if (*tmp == lexer->quote)
			lexer->quote = -1;
	if (tmp == str)
		return (tmp - 1);
	if (!(word = ft_strsub(str, 0, tmp - str)) ||
		!(join = ft_strjoin(token->content, word)))
		return (NULL);
	ft_strdel(&token->content);
	token->content = join;
	ft_strdel(&word);
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
		if ((type == T_WORD || lexer->quote != -1) &&
			!(tmp = lexer_addwordtoken(lexer, tmp)))
			return (1);
		else if (!(type == T_WORD || lexer->quote != -1) &&
			!(tmp = lexer_addsimpletoken(lexer, type, tmp)))
			return (1);
	}
	return (0);
}
