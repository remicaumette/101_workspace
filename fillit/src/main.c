/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:04:46 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:36:14 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static void	free_fillit(t_fillit *fillit)
{
	t_tet	*tmp;

	free(fillit->map);
	while (fillit->tetriminos)
	{
		tmp = fillit->tetriminos;
		fillit->tetriminos = fillit->tetriminos->next;
		free(tmp);
	}
}

static void	display_map(t_fillit *fillit)
{
	int	height;
	int	width;

	height = -1;
	while (++height < fillit->size && (width = -1))
	{
		while (++width < fillit->size)
			ft_putchar(fillit->map[height * fillit->size + width] == 0 ?
						'.' : fillit->map[height * fillit->size + width]);
		ft_putchar('\n');
	}
}

static void	init_map(t_fillit *fillit)
{
	t_tet	*list;
	int		nb;
	int		size;

	list = fillit->tetriminos;
	nb = 0;
	while (list != NULL)
	{
		++nb;
		list = list->next;
	}
	size = 2;
	while (size * size < nb)
		++size;
	fillit->size = size;
}

int			main(int argc, char **argv)
{
	t_fillit	fillit;

	if (argc != 2)
	{
		ft_putstr_fd(USAGE, 1);
		return (1);
	}
	fillit.filename = argv[1];
	if (!(fillit.tetriminos = parse_file(fillit.filename)))
	{
		ft_putstr_fd(ERROR, 1);
		return (1);
	}
	init_map(&fillit);
	if (!solve(&fillit))
	{
		ft_putstr_fd(ERROR, 2);
		return (1);
	}
	display_map(&fillit);
	free_fillit(&fillit);
	return (0);
}
