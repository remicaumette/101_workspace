/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fileinfo.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 01:48:02 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:11:37 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_size(t_fileinfo *file)
{
	if (S_ISBLK(file->stats->st_mode) || S_ISCHR(file->stats->st_mode))
	{
		file->minor = ft_itoa(minor(file->stats->st_rdev));
		return (!!(file->size = ft_itoa(major(file->stats->st_rdev))));
	}
	return (!(file->minor = NULL) &&
			(file->size = ft_lltoa(file->stats->st_size)));
}

t_fileinfo	*fileinfo_create(char *path, char *filename)
{
	t_fileinfo	*file;

	if (!(file = ft_memalloc(sizeof(t_fileinfo))) ||
		!(file->filename = ft_strdup(filename)) ||
		!(file->path = path_join(path, filename)) ||
		!(file->stats = ft_memalloc(sizeof(struct stat))) ||
		lstat(file->path, file->stats) ||
		!(file->owner = ft_strdup(getpwuid(file->stats->st_uid)->pw_name)) ||
		!(file->group = ft_strdup(getgrgid(file->stats->st_gid)->gr_name)) ||
		!get_size(file) ||
		!(file->nlink = ft_itoa(file->stats->st_nlink)))
	{
		fileinfo_destroy(&file);
		return (NULL);
	}
	file->link = file_readlink(file->path, file->stats);
	file->next = NULL;
	return (file);
}

void		fileinfo_destroy(t_fileinfo **file)
{
	if ((*file)->filename)
		ft_strdel(&((*file)->filename));
	if ((*file)->path)
		ft_strdel(&((*file)->path));
	if ((*file)->size)
		ft_strdel(&((*file)->size));
	if ((*file)->minor)
		ft_strdel(&((*file)->minor));
	if ((*file)->nlink)
		ft_strdel(&((*file)->nlink));
	if ((*file)->link)
		ft_strdel(&((*file)->link));
	if ((*file)->owner)
		ft_strdel(&((*file)->owner));
	if ((*file)->group)
		ft_strdel(&((*file)->group));
	if ((*file)->stats)
		ft_memdel((void **)&((*file)->stats));
	ft_memdel((void **)file);
}

void		fileinfo_insert(t_ls *ls, t_fileinfo *file)
{
	t_fileinfo	*prev;
	t_fileinfo	*curr;

	if (!ls->dir.files || (ls->reverse ?
		!ls->sort(ls->dir.files, file) : ls->sort(ls->dir.files, file)))
	{
		file->next = ls->dir.files;
		ls->dir.files = file;
	}
	else
	{
		prev = ls->dir.files;
		curr = ls->dir.files->next;
		while (curr && (ls->reverse ?
			ls->sort(curr, file) : !ls->sort(curr, file)))
		{
			prev = curr;
			curr = curr->next;
		}
		file->next = curr;
		prev->next = file;
	}
	ls->dir.files_count++;
}
