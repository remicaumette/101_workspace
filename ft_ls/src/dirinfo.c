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

t_dirinfo	*dirinfo_create(t_flags *flags, char *path)
{
	t_dirinfo	*info;

	if (!path || !(info = ft_memalloc(sizeof(t_dirinfo))))
		return (NULL);
	info->flags = flags;
	info->path = ft_strdup(path);
	info->total = 0;
	info->total_dir = 0;
	info->size_width = 0;
	info->user_width = 0;
	info->group_width = 0;
	info->link_width = 0;
	info->filename_width = 0;
	info->files = NULL;
	info->dirs = NULL;
	return (info);
}

t_fileinfo	*dirinfo_aggregate(t_dirinfo *info)
{
	DIR				*dir;
	struct dirent	*entry;
	t_fileinfo		*file;
	int				i;

	if (!(dir = opendir(info->path)))
		return (NULL);
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.' && !info->flags->hidden)
			continue ;
		if (!(file = fileinfo_create(entry->d_name)))
			return (NULL);
		fileinfo_insert(&info->files, file);
		if ((i = ft_strlen(file->filename)) > info->filename_width)
			info->filename_width = i;
		if (info->flags->display == long_format)
		{
			if ((i = ft_strlen(file->snlink)) > info->link_width)
				info->link_width = i;
			if ((i = ft_strlen(file->ssize)) > info->size_width)
				info->size_width = i;
			if ((i = ft_strlen(file->user)) > info->user_width)
				info->user_width = i;
			if ((i = ft_strlen(file->group)) > info->group_width)
				info->group_width = i;
		}
	}
	// todo: aggregate dir with dir
	return (info->files);
}

void		dirinfo_destroy(t_dirinfo **info)
{
	int	i;

	i = -1;
	while (++i < (*info)->total_dir)
		dirinfo_destroy(&(*info)->dirs[i]);
	ft_strdel(&(*info)->path);
	ft_memdel((void **)info);
}
