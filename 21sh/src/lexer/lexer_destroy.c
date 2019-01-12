/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_destroy.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 17:50:46 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 17:50:47 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	lexer_destroy(t_lexer *lexer)
{
	if (lexer)
	{
		lexer_cleanup(lexer);
		ft_memdel((void **)&lexer);
	}
}
