/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tetriminos.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:05:20 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:57:34 by rcaumett    ###    #+. /#+    ###.fr     */
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
