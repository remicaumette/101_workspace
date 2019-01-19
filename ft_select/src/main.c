/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 20:21:33 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 20:21:34 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

int	fail(t_select *select)
{
	select_destroy(select);
	return (1);
}

int	main(int argc, char **argv)
{
	t_select	select;

	(void)argc;
	if (select_init(&select, argv) || select_start(&select))
		return (fail(&select));
	select_destroy(&select);
	return (0);
}
