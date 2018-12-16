/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 22:28:34 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 22:32:01 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_redirection	*redirection_create(t_tokentype type, char *file,
	unsigned int in, unsigned int out)
{
	t_redirection	*redirection;

	if (!(redirection = ft_memalloc(sizeof(t_redirection))) ||
		!(redirection->file = ft_strdup(file)))
		return (NULL);
	redirection->type = type;
	redirection->in = in;
	redirection->out = out;
	redirection->next = NULL;
	return (redirection);
}

void			redirection_destroy(t_redirection *redirection)
{
	if (redirection)
	{
		if (redirection->file)
			ft_strdel(&redirection->file);
		ft_memdel((void **)&redirection);
	}
}
