/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:04:46 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:04:47 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	display_map(t_fillit *fillit)
{
	int	height;
	int	width;

	height = -1;
	while (++height < fillit->height && (width = -1))
		while (++width < fillit->width)
			ft_putchar(fillit->map[height * fillit->width + width]);
}

int		main(int argc, char **argv)
{
	t_fillit fillit;

	if (argc != 2)
	{
		ft_putstr_fd(USAGE, 2);
		return (1);
	}
	fillit.filename = argv[1];
	fillit.height = 0;
	fillit.width = 0;
	if (!(fillit.tetriminos = parse_file(fillit.filename)) || !solve(&fillit))
	{
		ft_putstr_fd(ERROR, 2);
		return (1);
	}
	display_map(&fillit);
	return (0);
}
