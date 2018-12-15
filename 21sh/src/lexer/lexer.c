/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:17:45 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 16:32:54 by rcaumett    ###    #+. /#+    ###.fr     */
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
	{"'", T_SQUOTE, 1},
	{"\"", T_DQUOTE, 1},
	{"|", T_PIPE, 1},
	{";", T_NEWLINE, 1},
	{"\n", T_NEWLINE, 1},
};

t_lexer		*lexer_create(void)
{
	t_lexer	*lexer;

	if (!(lexer = ft_memalloc(sizeof(t_lexer))))
		return (NULL);
	lexer->begin = NULL;
	lexer->end = NULL;
	lexer->count = 0;
	return (lexer);
}

void		lexer_cleanup(t_lexer *lexer)
{
	t_token	*token;
	t_token	*tmp;

	if (lexer)
	{
		token = lexer->begin;
		while (token)
		{
			tmp = token;
			token = token->next;
			lexer_deltoken(tmp);
		}
		lexer->begin = NULL;
		lexer->end = NULL;
		lexer->count = 0;
	}
}

void		lexer_destroy(t_lexer *lexer)
{
	if (lexer)
	{
		lexer_cleanup(lexer);
		ft_memdel((void **)&lexer);
	}
}

t_token		*lexer_addtoken(t_lexer *lexer, t_tokentype type,
	char *content)
{
	t_token	*token;

	if (!(token = ft_memalloc(sizeof(t_token))))
		return (NULL);
	token->type = type;
	token->content = NULL;
	token->next = NULL;
	if (content && !(token->content = ft_strdup(content)))
		return (NULL);
	if (!lexer->begin)
		lexer->begin = token;
	if (lexer->end)
		lexer->end->next = token;
	lexer->end = token;
	lexer->count++;
	return (token);
}

void		lexer_deltoken(t_token *token)
{
	if (token)
	{
		if (token->content)
			ft_strdel(&token->content);
		ft_memdel((void **)&token);
	}
}
