/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   command.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 22:18:25 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 22:26:24 by rcaumett    ###    #+. /#+    ###.fr     */
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

t_command	*command_destroy(t_command *command)
{
	if (command)
	{
		if (command->name)
			ft_strdel(&command->name);
		if (command->arguments)
			ft_strarr_del(command->arguments);
		if (command->redirection)

		ft_memdel((void **)&command);
	}
}

t_redirection	*command_addredirection(t_command *command, t_tokentype type,
	char *file, unsigned int in, unsigned int out)
{
	t_redirection	*redirection;

	if (!(redirection = ft_memalloc(sizeof(t_redirection))) ||
		!(redirection->file = ft_strdup(file)))
		return (NULL);
	redirection->type = type;
	redirection->in = in;
	redirection->out = out;
	redirection->next = command->redirection;
	return (command->redirection = redirection);
}
