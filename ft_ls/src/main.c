/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:16:24 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 16:39:18 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>


void			print_file(t_fileinfo *info)
{
	ft_putstr(info->permissions);
	ft_putstr("  ");
	ft_putnbr(info->nlink);
	ft_putstr(" ");
	ft_putstr(info->user);
	ft_putstr("  ");
	ft_putstr(info->group);
	ft_putstr("  ");
	ft_putstr(ft_lltoa(info->size));
	ft_putstr(" ");
	//ft_putstr(info->date);
	ft_putstr(" ");
	ft_putstr(info->filename);
	ft_putchar('\n');
}

// -r reverse sort
void	printlol(t_fileinfo *info)
{
	if (info->right)
		printlol(info->right);
	print_file(info);
	if (info->left)
		printlol(info->left);
}

int	main(void)
{
	t_dirinfo	*info;
	
	info = dirinfo_create(ft_strdup("."));
	dirinfo_aggregate(info, 0);
	printlol(info->files);
	return (0);
}
