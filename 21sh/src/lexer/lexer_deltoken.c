/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_deltoken.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:06:14 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:06:15 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	lexer_deltoken(t_token *token)
{
	if (token)
	{
		if (token->content)
			ft_strdel(&token->content);
		ft_memdel((void **)&token);
	}
}
