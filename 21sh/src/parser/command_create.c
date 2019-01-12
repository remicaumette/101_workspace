/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   command_create.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:10:30 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:10:30 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_command	*command_create(char *name)
{
	t_command	*command;

	if (!(command = ft_memalloc(sizeof(t_command))) ||
		!(command->name = ft_strdup(name)))
		return (NULL);
	command->arguments = NULL;
	command->redirection = NULL;
	return (command);
}
