/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_basic.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 14:49:46 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 14:51:25 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	action_basic(t_shell *shell, char *buf, int readed)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(shell->line, buf)))
		return (1);
	write(1, buf, readed);
	ft_strdel(&shell->line);
	shell->line = tmp;
	return (0);
}
