/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   command_parse.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:09:55 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:09:56 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_command	*command_parse(t_parser *parser)
{
	t_token		*curr;
	t_command	*cmd;

	if (!(curr = parser->curr) || curr->type != T_WORD ||
		!(cmd = command_create(curr->content)))
		return (NULL);
	curr = curr->next;
	while (curr && curr->type == T_WORD)
	{
		if (!(cmd->arguments = ft_strarr_add(cmd->arguments, curr->content)))
			return (NULL);
		curr = curr->next;
	}
	parser->curr = curr;
	return (cmd);
}
