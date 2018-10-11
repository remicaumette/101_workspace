/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:04:46 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 18:51:06 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	display_map(t_fillit *fillit)
{
	int	height;
	int	width;

	height = -1;
	while (++height < fillit->size && (width = -1))
		while (++width < fillit->size)
			ft_putchar(fillit->map[height * fillit->size + width]);
}

int		main(int argc, char **argv)
{
	t_fillit	fillit;
	t_tet		*tet;

	if (argc != 2)
	{
		ft_putstr_fd(USAGE, 2);
		return (1);
	}
	fillit.filename = argv[1];
	fillit.size = 0;
	ft_bzero(fillit.map, 676);
	if (!(fillit.tetriminos = parse_file(fillit.filename)))
	{
		ft_putstr_fd(ERROR, 2);
		return (1);
	}
	tet = fillit.tetriminos;
	while (tet && (fillit.size += 4))
		tet = tet->next;
	if (!solve(&fillit))
	{
		ft_putstr_fd(ERROR, 2);
		return (1);
	}
	display_map(&fillit);
	return (0);
}
