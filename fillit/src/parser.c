/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_line.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:07:53 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 14:27:18 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	validate_shape(t_tet *tet, int height, int width)
{
	(void)tet;
	(void)height;
	(void)width;
	return (4);
}

static int	validate_tetriminos(t_tet *tet)
{
	int	i;

	i = 0;
	while (i < 16 && !get_tetriminos_bit(tet, i / 4, i % 4))
		i++;
	if (i > 13)
		return (0);
	i = -1;
	while (++i < 4)
	{
		tet->width += !!(get_tetriminos_bit(tet, 0, i) + get_tetriminos_bit(tet, 1, i) + get_tetriminos_bit(tet, 2, i) + get_tetriminos_bit(tet, 3, i));
		tet->height += !!(get_tetriminos_bit(tet, i, 0) + get_tetriminos_bit(tet, i, 1) + get_tetriminos_bit(tet, i, 2) + get_tetriminos_bit(tet, i, 3));
	}
	return (validate_shape(tet, i / 4, i % 4) == 4);
}

int			parse_line(t_tet *tet, char *line, int nb)
{
	int	i;

	i = -1;
	while (line[++i] && (line[i] == '.' || line[i] == '#'))
		tet->content[nb > 1] += (line[i] == '#') << (i + ((nb % 2) * 4));
	return (nb == 3 ? validate_tetriminos(tet) : i == 4);
}

t_tet		*parse_file(char *filename)
{
	t_tet	*begin;
	char	*line;
	int		fd;
	int		status;
	int		lines;

	fd = open(filename, O_RDONLY);
	lines = 0;
	while ((status = get_next_line(fd, &line)))
	{
		if (!lines && !(add_tetriminos(&begin)))
			return (NULL);
		if (lines != 4 && parse_line(begin, line, lines) == 0)
			return (NULL);
		if (lines == 4 && *line)
			return (NULL);
		if (++lines == 5)
			lines = 0;
		ft_strdel(&line);
	}
	return (status == -1 ? NULL : reverse_tetriminos_list(&begin));
}
