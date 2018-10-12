/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:04:46 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:58:41 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	display_map(t_fillit *fillit, int map_size)
{
	int	height;
	int	width;
	(void) map_size;
	height = -1;
	while (++height < fillit->size && (width = -1))
	{
		while (++width < fillit->size)
			ft_putchar(fillit->map[height * (map_size) + width] ?
						fillit->map[height * (map_size) + width] : '.');
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	t_fillit	fillit;
	t_tet		*tet;

	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (1);
	}
	fillit.filename = argv[1];
	fillit.size = 0;
	ft_bzero(fillit.map, MAP_SIZE);
	if (!(fillit.tetriminos = parse_file(fillit.filename)))
	{
		ft_putstr(ERROR);
		return (1);
	}
	tet = fillit.tetriminos;
	while (tet && (fillit.size += 4))
		tet = tet->next;
	if (!solve(&fillit))
	{
		ft_putstr(ERROR);
		return (1);
	}
	//display_map(&fillit);
	return (0);
}
