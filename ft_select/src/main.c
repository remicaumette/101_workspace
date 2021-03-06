/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 20:21:33 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 17:14:18 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

static int	fail(t_select *select)
{
	select_destroy(select);
	return (1);
}

static void	handle_signal(int s)
{
	if (s == SIGWINCH)
		select_render(&g_select);
}

int			main(int argc, char **argv)
{
	(void)argc;
	signal(SIGWINCH, handle_signal);
	if (select_init(&g_select, argv) || select_start(&g_select))
		return (fail(&g_select));
	select_destroy(&g_select);
	return (0);
}
