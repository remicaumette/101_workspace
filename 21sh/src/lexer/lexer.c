/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:17:45 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 09:45:18 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_lexer		*lexer_create()
{
	t_lexer	*lexer;

	if (!(lexer = ft_memalloc(sizeof(t_lexer))))
		return (NULL);
	lexer->begin = NULL;
	lexer->end = NULL;
	lexer->count = 0;
	return (lexer);
}

void		lexer_destroy(t_lexer *lexer)
{
	t_token	*token;

	if (lexer)
	{
		token = lexer->begin;
		while (token)
		{
			lexer_deltoken(token);
			token = token->next;
		}
		lexer->begin = NULL;
		lexer->end = NULL;
		lexer->count = 0;
		ft_memdel((void **)&lexer);
	}
}
