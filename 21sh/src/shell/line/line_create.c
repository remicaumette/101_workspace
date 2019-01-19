/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_create.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 13:14:10 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 14:14:07 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	get_winsize(t_winsize *window)
{
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, window) == -1)
		return (FAIL);
	return (SUCCESS);
}

t_line		*line_create(void)
{
	t_line		*line;

	if ((line = malloc(sizeof(t_line))) == NULL)
		return (NULL);
	line->content = NULL;
	line->size = 0;
	line->cursor = 1;
	if (get_winsize(&(line->window)) != SUCCESS)
		return (NULL);
	return (line);
}
