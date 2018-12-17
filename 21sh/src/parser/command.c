/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   command.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 22:18:25 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 15:08:21 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_command	*command_create(char *name)
{
	t_command	*command;

	if (!(command = ft_memalloc(sizeof(t_command))) ||
		!(command->name = name))
		return (NULL);
	command->arguments = NULL;
	command->redirection = NULL;
	return (command);
}

void		command_destroy(t_command *command)
{
	t_redirection	*tmp;
	t_redirection	*curr;

	if (command)
	{
		if (command->name)
			ft_strdel(&command->name);
		if (command->arguments)
			ft_strarr_del(command->arguments);
		if (command->redirection)
		{
			curr = command->redirection;
			while (curr)
			{
				tmp = curr;
				curr = curr->next;
				redirection_destroy(tmp);
			}
		}
		ft_memdel((void **)&command);
	}
}

t_command	*command_parse(t_parser *parser)
{
	t_token		*curr;
	t_command	*cmd;

	if (!(curr = parser->curr) || curr->type != T_WORD ||
		!(cmd = command_create(curr->content)))
		return (NULL);
	curr = curr->next && curr->next->type == T_WORD ? curr->next : NULL;
	while (curr && curr->type == T_WORD)
	{
		if (!(cmd->arguments = ft_strarr_add(cmd->arguments, curr->content)))
			return (NULL);
		curr = curr->next;
	}
	parser->curr = curr;
	return (cmd);
}
