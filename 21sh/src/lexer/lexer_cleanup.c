/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_cleanup.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 17:50:19 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 17:50:28 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	lexer_cleanup(t_lexer *lexer)
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
		lexer->quote = -1;
	}
}
