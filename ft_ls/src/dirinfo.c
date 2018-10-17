/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:27:03 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 15:27:03 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirinfo	*dirinfo_create(char *cwd)
{
	t_dirinfo	*info;

	if (!(info = ft_memalloc(sizeof(t_dirinfo))))
		return (NULL);
	info->cwd = cwd;
	info->total = 0;
	info->total_dir = 0;
	info->files = NULL;
	info->dirs = NULL;
	return (info);
}

t_fileinfo	*dirinfo_aggregate(t_dirinfo *info, int aggregate_dir)
{
	DIR				*dir;
	struct dirent	*entry;
	t_fileinfo		*file;

	(void) aggregate_dir;
	if (!(dir = opendir(".")))
		return (NULL);
	while ((entry = readdir(dir)))
	{
		if (ft_strequ(entry->d_name, ".") || ft_strequ(entry->d_name, ".."))
			continue ;
		file = fileinfo_create(ft_strdup(entry->d_name));
		fileinfo_insert(&info->files, file);
	}
	// todo: aggregate dir with dir
	// todo: check errno
	return (info->files);
}

void		dirinfo_destroy(t_dirinfo **info)
{
	int i;

	i = -1;
	while (++i < (*info)->total_dir)
		dirinfo_destroy(&(*info)->dirs[i]);
	ft_strdel(&(*info)->cwd);
	// todo: delete files if files
	ft_memdel((void **)info);
}
