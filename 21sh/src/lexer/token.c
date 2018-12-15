/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:30:12 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 21:42:18 by rcaumett    ###    #+. /#+    ###.fr     */
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
	if (type == T_SQUOTE || type == T_DQUOTE)
		lexer->quote = lexer->quote == -1 ? *str : -1;
	if (!(lexer_addtoken(lexer, type, NULL)))
		return (NULL);
	return (str + info.len - 1);
}

static char		*ft_strjoinc(char **mot, char c)
{
	char	*tmp;
	char	m[2];

	m[0] = c;
	m[1] = 0;
	if (!(tmp = ft_strjoin(*mot, m)))
		return (NULL);
	ft_strdel(mot);
	return (*mot = tmp);
}

static char		*lexer_addwordtoken(t_lexer *lexer, char *str)
{
	char	*tmp;
	char	*word;

	tmp = str - 1;
	word = NULL;
	while (*++tmp && !(((*tmp == '\t' || *tmp == ' ' || lexer_gettype(tmp) != T_WORD) &&
		lexer->quote == -1) || (lexer->quote != -1 && lexer->quote == *tmp)))
		if (!(ft_strjoinc(&word, *tmp)))
			return (NULL);
	if (!(lexer_addtoken(lexer, T_WORD, word)))
		return (NULL);
	tmp -= (word != NULL);
	ft_strdel(&word);
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
		else if (type != T_WORD && !(tmp = lexer_addsimpletoken(lexer, type, tmp)))
			return (1);
	}
	return (0);
}
