#include "minishell.h"

t_token	*token_create(t_symbol symbol, t_operator op, char *content)
{
	t_token	*token;

	if (!(token = ft_memalloc(sizeof(t_token))))
		return (NULL);
	token->symbol = symbol;
	token->op = op;
	token->content = content;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

void	token_destroy(t_token *token)
{
	t_token	*curr;
	t_token	*next;

	next = token;
	while (next)
	{
		curr = next;
		next = curr->next;
		ft_strdel(&curr->content);
		ft_memdel((void **)&curr);
	}
}
