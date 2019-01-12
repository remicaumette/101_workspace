/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection_create.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:13:34 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:13:35 by rcaumett    ###    #+. /#+    ###.fr     */
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
