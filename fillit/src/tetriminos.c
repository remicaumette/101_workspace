/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tetriminos.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:05:20 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 13:53:56 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_tet	*add_tetriminos(t_tet **begin)
{
	t_tet	*tet;

	if (!(tet = ft_memalloc(sizeof(*tet))))
		return (NULL);
	if ((tet->letter = *begin ? (*begin)->letter + 1 : 'A') > 'Z')
		return (NULL);
	tet->height = 0;
	tet->width = 0;
	tet->content[0] = 0;
	tet->content[1] = 0;
	tet->next = *begin;
	return (*begin = tet);
}

t_tet	*reverse_tetriminos_list(t_tet **begin)
{
	t_tet	*prev;
	t_tet	*first;
	t_tet	*tmp;

	if (!begin)
		return (NULL);
	first = *begin;
	prev = NULL;
	while (first)
	{
		tmp = first->next;
		first->next = prev;
		prev = first;
		first = tmp;
	}
	return (*begin = prev);
}

t_uint8	get_tetriminos_bit(t_tet *tet, const t_uint8 height,
					const t_uint8 width)
{
	int	calc;

	calc = height * 4 + width;
	return (!!(tet->content[calc > 7] & (1 << (calc - (calc > 7) * 8))));
}

void	place_tet(t_fillit *fillit, t_tet *tet, int map_x, int map_y)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (get_tetriminos_bit(tet, i / 4, i % 4))
			fillit->map[map_x + i % 4 + (map_y + i / 4) * fillit->size] =
				tet->letter;
}

void	remove_tet(t_fillit *fillit, t_tet *tet, int map_x, int map_y)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (get_tetriminos_bit(tet, i / 4, i % 4))
			fillit->map[map_x + i % 4 + (map_y + i / 4) * fillit->size] = 0;
}
