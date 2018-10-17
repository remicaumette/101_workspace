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

t_dirinfo	*dirinfo_create(char *cwd)
{
	t_dirinfo	*info;

	if (!cwd || !(info = ft_memalloc(sizeof(t_dirinfo))))
		return (NULL);
	info->cwd = ft_strdup(cwd);
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

t_fileinfo	*dirinfo_aggregate(t_dirinfo *info, int aggregate_dir)
{
	DIR				*dir;
	struct dirent	*entry;
	t_fileinfo		*file;
	int				i;

	(void)aggregate_dir;
	if (!(dir = opendir(info->cwd)))
		return (NULL);
	while ((entry = readdir(dir)))
	{
		if (!(file = fileinfo_create(entry->d_name)))
			return (NULL);
		fileinfo_insert(&info->files, file);
		if ((i = ft_strlen(file->ssize)) > info->link_width)
			info->link_width = i;
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
	ft_strdel(&(*info)->cwd);
	fileinfo_recursive_destroy(&(*info)->files);
	ft_memdel((void **)info);
}
