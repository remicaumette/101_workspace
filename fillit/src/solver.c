/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:05:43 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:39:45 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_uint8	can_place(t_fillit *fillit, t_tet *tet, int map_x, int map_y)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (get_tetriminos_bit(tet, i / 4, i % 4) && (
				i / 4 + map_y >= fillit->size ||
				i % 4 + map_x >= fillit->size ||
				i / 4 + map_y < 0 || i % 4 + map_x < 0 ||
				fillit->map[map_x + i % 4 + (map_y + i / 4) * fillit->size]
				))
			return (0);
	return (1);
}

t_uint8	fill_map(t_fillit *fillit, t_fillit *final)
{
	int	i;
	int	j;

	i = fillit->size;
	while (--i >= 0)
	{
		j = 0;
		while (j < fillit->size && !(fillit->map[i + j * fillit->size] ||
				fillit->map[i * fillit->size + j]))
			j++;
		if (j < fillit->size)
			break ;
	}
	if (i + 1 > final->size)
		return (1);
	final->size = i + 1;
	i = -1;
	while (++i < fillit->size * fillit->size)
		final->map[i] = fillit->map[i];
	return (1);
}

t_uint8	test_solve_fillit(t_fillit *fillit, t_tet *current, t_fillit *final)
{
	int	i;
	int	size;

	size = fillit->size;
	i = -4 * fillit->size;
	if (current == 0)
		return (fill_map(fillit, final));
	while (++i < size * size)
		if (i % size < final->size && i / size < final->size &&
			can_place(fillit, current, i % size, i / size))
		{
			place_tet(fillit, current, i % size, i / size);
			test_solve_fillit(fillit, current->next, final);
			remove_tet(fillit, current, i % size, i / size);
		}
	return (0);
}

t_uint8	solve(t_fillit *fillit)
{
	t_fillit	temp;
	t_tet		*curr;

	temp.tetriminos = 0;
	temp.size = fillit->size;
	ft_bzero(temp.map, MAP_SIZE);
	curr = fillit->tetriminos;
	test_solve_fillit(fillit, curr, &temp);
	display_map(&temp, fillit->size);
	return (1);
}
