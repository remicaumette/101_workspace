/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dirinfo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 01:14:16 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:40:28 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	dirinfo_insert_file(t_ls *ls, t_fileinfo *file)
{
	int	i;

	if ((i = ft_strlen(file->filename)) > ls->dir.filename_width)
		ls->dir.filename_width = i;
	if ((i = ft_strlen(file->nlink)) > ls->dir.link_width)
		ls->dir.link_width = i;
	if ((i = ft_strlen(file->size) + ft_strlen(file->minor)) >
		ls->dir.size_width)
		ls->dir.size_width = i;
	if ((i = ft_strlen(file->owner)) > ls->dir.user_width)
		ls->dir.user_width = i;
	if ((i = ft_strlen(file->group)) > ls->dir.group_width)
		ls->dir.group_width = i;
	ls->dir.total += file->stats->st_blocks;
	fileinfo_insert(ls, file);
}

int		dirinfo_init(t_ls *ls, char *path)
{
	if (!(ls->dir.path = (path ? ft_strdup(path) : NULL)))
		return (1);
	ls->dir.total = 0;
	ls->dir.size_width = 0;
	ls->dir.user_width = 0;
	ls->dir.group_width = 0;
	ls->dir.link_width = 0;
	ls->dir.filename_width = 0;
	ls->dir.files_count = 0;
	ls->dir.files = NULL;
	return (0);
}

int		dirinfo_adddirectories(t_ls *ls, char ***directories)
{
	t_fileinfo	*file;

	if (!ls->recursive)
		return (0);
	file = ls->dir.files;
	while (file)
	{
		if (S_ISDIR(file->stats->st_mode) &&
			!ft_strequ(file->filename, "..") &&
			!ft_strequ(file->filename, ".") &&
			!(*directories = ft_strarr_add(*directories, file->path)))
			return (1);
		file = file->next;
	}
	return (0);
}

int		dirinfo_aggregate(t_ls *ls, char ***directories)
{
	DIR				*dir;
	struct dirent	*entry;
	t_fileinfo		*file;

	if (!(dir = opendir(ls->dir.path)))
	{
		ls_printerror(ls->dir.path);
		return (0);
	}
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.' && !ls->hidden)
			continue ;
		if (!(file = fileinfo_create(ls->dir.path, entry->d_name)))
			continue ;
		dirinfo_insert_file(ls, file);
	}
	return (!!closedir(dir) || dirinfo_adddirectories(ls, directories));
}

void	dirinfo_destroy(t_dirinfo *dir)
{
	t_fileinfo	*file;
	t_fileinfo	*tmp;

	if (dir->path)
		ft_strdel(&dir->path);
	file = dir->files;
	while (file)
	{
		tmp = file;
		file = file->next;
		fileinfo_destroy(&tmp);
	}
}
