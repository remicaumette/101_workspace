/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_inser.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 13:24:41 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:24:05 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static inline void	inser_begin(char *new, t_line *line, char c, int i)
{
	new[0] = c;
	while (line->content[++i])
		new[i + 1] = line->content[i];
	new[i + 1] = '\0';
}

static inline void	inser_mid(char *new, t_line *line, char c, int i)
{
	while (++i < line->cursor - 1)
		new[i] = line->content[i];
	new[i] = c;
	while (line->content[i])
	{
		new[i + 1] = line->content[i];
		i++;
	}
	new[i + 1] = '\0';
}

static inline void	inser_end(char *new, t_line *line, char c, int i)
{
	if (line->content)
		while (line->content[++i])
			new[i] = line->content[i];
	else
		i = 0;
	new[i++] = c;
	new[i] = '\0';
}

int					line_inser(t_line *line, char c)
{
	int		i;
	char	*tmp;

	i = -1;
	if (!(tmp = ft_strnew(line->size + 1)))
		return (FAIL);
	if (line->cursor == (line->size + 1))
		inser_end(tmp, line, c, i);
	else if (line->cursor != 1)
		inser_mid(tmp, line, c, i);
	else if (line->cursor == 1)
		inser_begin(tmp, line, c, i);
	line->size++;
	line->cursor++;
	ft_strdel(&line->content);
	line->content = tmp;
	return (SUCCESS);
}
