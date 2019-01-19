/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_stop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 11:08:59 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:08:13 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_stop(t_shell *shell)
{
	if (!shell->line->size)
		return (FAIL); // replace by exit
	return (SUCCESS);
}
