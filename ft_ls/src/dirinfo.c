/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dirinfo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:27:03 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 18:00:38 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		dirinfo_init(t_dirinfo *dir, char *path)
{
	dir->path = ft_strdup(path);
	dir->total = 0;
	dir->total_dir = 0;
	dir->size_width = 0;
	dir->user_width = 0;
	dir->group_width = 0;
	dir->link_width = 0;
	dir->filename_width = 0;
	dir->files = NULL;
}

static int	dirinfo_aggregate_file(t_dirinfo *dir, t_flags *flags, struct dirent *entry)
{
	t_fileinfo		*file;
	int				i;

	if (!(file = fileinfo_create(entry->d_name)))
		return (0);
	fileinfo_insert(flags, &dir->files, file, get_sort_func(flags->sort));
	if ((i = ft_strlen(file->filename)) > dir->filename_width)
		dir->filename_width = i;
	if (flags->display == long_format)
	{
		if ((i = ft_strlen(file->nlink)) > dir->link_width)
			dir->link_width = i;
		if ((i = ft_strlen(file->size)) > dir->size_width)
			dir->size_width = i;
		if ((i = ft_strlen(file->passwd->pw_name)) > dir->user_width)
			dir->user_width = i;
		if ((i = ft_strlen(file->group->gr_name)) > dir->group_width)
			dir->group_width = i;
	}
	return (1);
}

static int	dirinfo_single_file(t_dirinfo *dir, t_flags *flags)
{
	t_fileinfo	*file;

	if (!(file = fileinfo_create(dir->path)))
		return (0);
	dir->files = file;
	dir->filename_width = ft_strlen(file->filename);
	if (flags->display == long_format)
	{
		dir->link_width = ft_strlen(file->nlink);
		dir->size_width = ft_strlen(file->size);
		dir->user_width = ft_strlen(file->passwd->pw_name);
		dir->group_width = ft_strlen(file->group->gr_name);
	}
	return (1);
}

int			dirinfo_aggregate(t_dirinfo *info, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*entry;

	if (!(dir = opendir(info->path)))
		return (dirinfo_single_file(info, flags));
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.' && !flags->hidden)
			continue ;
		if (!dirinfo_aggregate_file(info, flags, entry))
			return (0);
	}
	return (!closedir(dir));
}
