/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dirinfo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:27:03 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 17:23:10 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		dirinfo_init(t_dirinfo *dir, char *path)
{
	dir->path = ft_strdup(path);
	dir->total = 0;
	dir->size_width = 0;
	dir->user_width = 0;
	dir->group_width = 0;
	dir->link_width = 0;
	dir->filename_width = 0;
	dir->files = NULL;
}

static int	dirinfo_aggregate_file(t_dirinfo *dir, t_options *options,
	struct dirent *entry, char ***paths)
{
	t_fileinfo		*file;
	int				i;

	if (!(file = fileinfo_create(dir->path, entry->d_name)))
		return (0);
	fileinfo_insert(options, &dir->files, file);
	dir->total += (int)file->stats->st_blocks;
	if (options->recursive && S_ISDIR(file->stats->st_mode) &&
		!ft_strequ(file->filename, ".") && !ft_strequ(file->filename, ".."))
	{
		*paths = ft_strarr_add(*paths, file->path);
		options->paths_count++;
	}
	if ((i = ft_strlen(file->filename)) > dir->filename_width)
		dir->filename_width = i;
	if ((i = ft_strlen(file->nlink)) > dir->link_width)
		dir->link_width = i;
	if ((i = ft_strlen(file->size)) > dir->size_width)
		dir->size_width = i;
	if ((i = ft_strlen(file->owner)) > dir->user_width)
		dir->user_width = i;
	if ((i = ft_strlen(file->group)) > dir->group_width)
		dir->group_width = i;
	return (1);
}

static int	dirinfo_single_file(t_dirinfo *dir)
{
	t_fileinfo	*file;

	if (!(file = fileinfo_create(NULL, dir->path)))
		return (0);
	dir->files = file;
	dir->total = -1;
	dir->filename_width = ft_strlen(file->filename);
	dir->link_width = ft_strlen(file->nlink);
	dir->size_width = ft_strlen(file->size);
	dir->user_width = ft_strlen(file->owner);
	dir->group_width = ft_strlen(file->group);
	return (1);
}

int			dirinfo_aggregate(t_dirinfo *info, t_options *options,
	char ***paths)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		stats;

	if (!(dir = opendir(info->path)))
	{
		lstat(info->path, &stats);
		return (S_ISDIR(stats.st_mode) ? 0 : dirinfo_single_file(info));
	}
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.' && !options->hidden)
			continue ;
		if (!dirinfo_aggregate_file(info, options, entry, paths))
			return (0);
	}
	return (!closedir(dir));
}
