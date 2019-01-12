/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection_destroy.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:13:54 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:13:55 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	redirection_destroy(t_redirection *redirection)
{
	if (redirection)
	{
		if (redirection->file)
			ft_strdel(&redirection->file);
		ft_memdel((void **)&redirection);
	}
}
