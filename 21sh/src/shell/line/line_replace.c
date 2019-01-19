/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_replace.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 12:18:25 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 12:18:28 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		line_replace(t_line *line, char *src)
{
	ft_strdel(&line->content);
	line->content = src;
	line->size = ft_strlen(src);
	line->cursor = line->size + 1;
}
