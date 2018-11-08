/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:05:43 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:20:33 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	can_place(t_fillit *fillit, t_tet *tet, int map_x, int map_y)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (get_tetriminos_bit(tet, i / 4, i % 4) &&
				(map_x + i % 4 < 0 || map_y + i / 4 < 0 ||
				i / 4 + map_y >= fillit->size ||
				i % 4 + map_x >= fillit->size ||
				fillit->map[map_x + i % 4 + (map_y + i / 4) * fillit->size]))
			return (0);
	return (1);
}

static int	place_tet(t_fillit *fillit, t_tet *tet, int map_x, int map_y)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (get_tetriminos_bit(tet, i / 4, i % 4))
			fillit->map[map_x + i % 4 +
				(map_y + i / 4) * fillit->size] = tet->letter;
	return (1);
}

static int	remove_tet(t_fillit *fillit, t_tet *tet, int map_x, int map_y)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (get_tetriminos_bit(tet, i / 4, i % 4))
			fillit->map[map_x + i % 4 + (map_y + i / 4) * fillit->size] = 0;
	return (1);
}

static int	place_all_tets(t_fillit *fillit, t_tet *tet)
{
	int	x;
	int	y;

	if (tet == NULL)
		return (1);
	y = -4;
	while (++y < fillit->size)
	{
		x = -4;
		while (++x < fillit->size)
			if (can_place(fillit, tet, x, y))
			{
				place_tet(fillit, tet, x, y);
				if (place_all_tets(fillit, tet->next))
					return (1);
				remove_tet(fillit, tet, x, y);
			}
	}
	return (0);
}

t_uint8		solve(t_fillit *fillit)
{
	if ((fillit->map = (char *)malloc(fillit->size * fillit->size)) == NULL)
		return (0);
	ft_bzero(fillit->map, fillit->size * fillit->size);
	while (!place_all_tets(fillit, fillit->tetriminos))
	{
		free(fillit->map);
		fillit->size = fillit->size + 1;
		if ((fillit->map = (char *)malloc(fillit->size * fillit->size)) == NULL)
			return (0);
		ft_bzero(fillit->map, fillit->size * fillit->size);
	}
	return (1);
}
