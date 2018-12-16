/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   command.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 22:18:25 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 01:02:26 by rcaumett    ###    #+. /#+    ###.fr     */
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
