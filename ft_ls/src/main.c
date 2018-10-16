/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:16:24 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 17:16:25 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void			print_file(t_btree_file *file)
{
	ft_putstr(get_permissions(file->stat));
	ft_putstr("  ");
	ft_putnbr(file->stat->st_nlink);
	ft_putstr(" ");
	ft_putstr(file->passwd->pw_name);
	ft_putstr("  ");
	ft_putstr(file->group->gr_name);
	ft_putstr("  ");
	ft_putstr(ft_lltoa(file->stat->st_size));
	ft_putstr("  ");
	ft_putstr(get_date(file->stat));
	ft_putstr("  ");
	ft_putstr(file->filename);
	ft_putchar('\n');
}

t_btree_file	*get_file_info(char *filename)
{
	t_btree_file *file;

	if (!(file = btree_file_create(filename)))
		return (NULL);
	if (stat(filename, file->stat))
		return (NULL);
	if (!(file->passwd = getpwuid(file->stat->st_uid)))
		return (NULL);
	if (!(file->group = getgrgid(file->stat->st_gid)))
		return (NULL);
	return (file);
}

int	main(void)
{
	t_btree_file	*file;
	
	file = get_file_info(ft_strdup("auteur"));
	print_file(file);
	ft_memdel((void **)&file);
	return (0);
}
