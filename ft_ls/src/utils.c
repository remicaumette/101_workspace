/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:26:40 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 16:15:57 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			parse_flag(t_flags *flags, char c)
{
	if (c == 't')
		flags->sort = sort_time;
	else if (c == 'S')
		flags->sort = sort_size;
	else if (c == 'r')
		flags->reverse = 1;
	else if (c == 'R')
		flags->recursive = 1;
	else if (c == 'a')
		flags->hidden = 1;
	else if (c == 'l')
		flags->display = long_format;
	else if (c == '1')
		flags->display = one_per_line;
	else if (c == 'C')
		flags->display = many_per_line;
	else if (c == 'm')
		flags->display = with_commas;
	else
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd("\nusage: ft_ls [-trRlaC1] [file ...]\n", 2);
		exit(1);
	}
}

void				parse_flags(t_flags *flags, char **argv)
{
	int	i;
	int	j;

	flags->display = vertical;
	flags->hidden = 0;
	flags->recursive = 0;
	flags->reverse = 0;
	flags->sort = sort_name;
	i = 0;
	while (argv[++i])
	{
		j = 0;
		if (argv[i][j] != '-')
			break ;
		while (argv[i][++j])
			parse_flag(flags, argv[i][j]);
	}
}
