/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:16:24 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 18:13:55 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	debug_file(t_fileinfo *info)
{
	printf("t_fileinfo {\n");
	printf("\tfilename = '%s'\n", info->filename);
	printf("\tpermissions = '%s'\n", info->permissions);
	printf("\tnlink = %d\n", info->nlink);
	printf("\tsnlink = '%s'\n", info->snlink);
	printf("\tuser = '%s'\n", info->user);
	printf("\tgroup = '%s'\n", info->group);
	printf("\tsize = %lld\n", info->size);
	printf("\tssize = '%s'\n", info->ssize);
	printf("\tdate_year = '%s'\n", info->date_year);
	printf("\tdate_month = '%s'\n", info->date_month);
	printf("\tdate_day = '%s'\n", info->date_day);
	printf("\tdate_hour = '%s'\n", info->date_hour);
	printf("\tdate_min = '%s'\n", info->date_min);
	printf("}\n");
}

void	print_file(t_fileinfo *info)
{
	ft_putstr(info->permissions);
	ft_putstr("  ");

	/*
	ft_putstr(info->permissions);
	ft_putstr("  ");
	ft_putstr(info->snlink);
	ft_putstr(" ");
	ft_putstr(info->user);
	ft_putstr("  ");
	ft_putstr(info->group);
	ft_putstr("  ");
	ft_putstr(info->ssize);
	ft_putstr(" ");
	//ft_putstr(info->date);
	ft_putstr(" ");
	ft_putstr(info->filename);
	ft_putchar('\n');*/
	ft_putchar('\n');
}

// -r reverse sort
void	print_directory(t_dirinfo *dir, t_fileinfo *file)
{
	if (file->right)
		print_directory(dir, file->right);
	print_file(file);
	if (file->left)
		print_directory(dir, file->left);
}

void	print_directory_reverse(t_dirinfo *dir, t_fileinfo *file)
{
	if (file->left)
		print_directory(dir, file->left);
	print_file(file);
	if (file->right)
		print_directory(dir, file->right);
}

int		main(int argc, char **argv)
{
	t_dirinfo	*info;

	if (!(info = dirinfo_create(argc == 1 ? "." : argv[1])) ||
		!dirinfo_aggregate(info, 0))
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	print_directory(info, info->files);
	dirinfo_destroy(&info);
	return (0);
}
