/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_end.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 19:34:17 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 19:34:26 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	action_end(t_shell *shell)
{
	while (shell->line->cursor <= shell->line->size)
		action_arrow_right(shell);
	return (SUCCESS);
}
