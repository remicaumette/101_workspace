/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_destroy.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 13:19:04 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 15:46:14 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		line_destroy(t_line **line)
{
	ft_strdel(&(*line)->content);
	free(*line);
	line = NULL;
}
