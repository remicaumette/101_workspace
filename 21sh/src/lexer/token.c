/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:30:12 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 10:55:30 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_token		*lexer_addtoken(t_lexer *lexer, t_tokentype type,
	t_operatortype op, char *content)
{
	t_token	*token;

	if (!(token = ft_memalloc(sizeof(t_token))))
		return (NULL);
	token->type = type;
	token->op = op;
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
void		print_token(t_token *token)
{
	static const char type[4][20] = { "WORD", "OPERATOR", "NEWLINE", "IO_NUMBER" };
	static const char op[11][20] = { "NONE", "AND_IF", "OR_IF", "DSEMI", "DLESS", "DGREAT", "LESSAND", "GREATAND", "LESSGREAT", "DLESSDASH", "CLOBBER" };
	printf("=== TOKEN\n");
	printf("token->type: %s\n", type[token->type]);
	printf("token->op: %s\n", op[token->op]);
	printf("token->content: %s\n", token->content);
	printf("token->next: %p\n", token->next);
}

int			lexer_tokenlen(t_token *token)
{
	if (token->type == WORD)
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

	tmp = str - 1;
	while (*++tmp)
	{
		if (*tmp == ' ' || *tmp == '\t')
			continue ;
		op = lexer_getop(tmp);
		if (op)
			type = OPERATOR;
		else if (*tmp == '\n' || *tmp == ';')
			type = NEWLINE;
		else
			type = WORD;
		if (!(curr = lexer_addtoken(lexer, type, op, NULL)))
			return (1);
		print_token(curr);
		tmp += lexer_tokenlen(curr);
	}
	return (0);
}
