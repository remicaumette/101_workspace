/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expansion.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 18:27:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 04:09:40 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char	*parser_expandword(t_parser *parser, t_token *token)
{
	char	*word;
	char	*tmp;

	word = NULL;
	tmp = token->content - 1;
	while (*++tmp)
	{
	}
	return (tmp);
}
