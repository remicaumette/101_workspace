/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:07:53 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:15:56 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	validate_shape(t_tet *tet)
{
	int	adj;
	int	i;
	int	nb;

	adj = 0;
	i = -1;
	nb = 0;
	while (++i < 16)
		if (get_tetriminos_bit(tet, i / 4, i % 4))
		{
			nb++;
			if (i / 4 > 0 && get_tetriminos_bit(tet, i / 4 - 1, i % 4))
				adj++;
			if (i % 4 > 0 && get_tetriminos_bit(tet, i / 4, i % 4 - 1))
				adj++;
			if (i / 4 < 3 && get_tetriminos_bit(tet, i / 4 + 1, i % 4))
				adj++;
			if (i % 4 < 3 && get_tetriminos_bit(tet, i / 4, i % 4 + 1))
				adj++;
		}
	return (adj == 6 || adj == 8 ? nb : 0);
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
		tet->width += !!(get_tetriminos_bit(tet, 0, i) +
				get_tetriminos_bit(tet, 1, i) + get_tetriminos_bit(tet, 2, i) +
				get_tetriminos_bit(tet, 3, i));
		tet->height += !!(get_tetriminos_bit(tet, i, 0) +
				get_tetriminos_bit(tet, i, 1) + get_tetriminos_bit(tet, i, 2) +
				get_tetriminos_bit(tet, i, 3));
	}
	return (validate_shape(tet) == 4);
}

static int	parse_line(t_tet *tet, char *line, int nb)
{
	int	i;

	i = -1;
	while (line[++i] && (line[i] == '.' || line[i] == '#'))
		tet->content[nb > 1] += (line[i] == '#') << (i + ((nb % 2) * 4));
	return (nb == 3 ? validate_tetriminos(tet) : i == 4 && !line[i]);
}

t_tet		*parse_file(char *filename)
{
	t_tet	*begin;
	char	*line;
	int		fd;
	int		status;
	int		lines;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	lines = 0;
	begin = NULL;
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
	return (status == -1 || lines != 4 ?
			NULL : reverse_tetriminos_list(&begin));
}
