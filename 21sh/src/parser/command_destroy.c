/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   command_destroy.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:10:15 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:10:15 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	command_destroy(t_command *command)
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
