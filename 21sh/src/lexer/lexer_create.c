/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_create.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 17:49:59 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 17:50:00 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_lexer	*lexer_create(void)
{
	t_lexer	*lexer;

	if (!(lexer = ft_memalloc(sizeof(t_lexer))))
		return (NULL);
	lexer->begin = NULL;
	lexer->end = NULL;
	lexer->count = 0;
	lexer->quote = -1;
	return (lexer);
}
