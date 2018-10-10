/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:05:43 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:06:39 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	debug_map(unsigned char map[])
{
	for (int i = 0; i < 8; i++)
	{
		if (i == 4)
			ft_putchar('\n');
		ft_putchar((map[0] & (1 << i)) ? '1' : '0');
	}
	ft_putchar('\n');
	for (int i = 0; i < 8; i++)
	{
		if (i == 4)
			ft_putchar('\n');
		ft_putchar((map[1] & (1 << i)) ? '1' : '0');
	}
	ft_putchar('\n');
}

t_uint8	solve(t_fillit *fillit)
{
	t_tet	*curr;

	curr = fillit->tetriminos;
	while (curr)
	{
		printf("width: %d height: %d\n", curr->width, curr->height);
		debug_map(curr->content);
		curr = curr->next;
	}
	return (1);
}
