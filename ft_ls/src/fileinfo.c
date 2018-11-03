/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fileinfo.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:27:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 02:46:57 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static t_fileinfo	*fileinfo_init(t_fileinfo *info)
{
	char	buf[1024];
	int		size;

	info->link = NULL;
	if (S_ISLNK(info->stats->st_mode))
	{
		size = readlink(info->path, buf, 1024);
		if (!(info->link = ft_strnew(size)))
		{
			fileinfo_destroy(&info);
			return (NULL);
		}
		ft_strncpy(info->link, buf, size);
	}
	info->left = NULL;
	info->right = NULL;
	return (info);
}

t_fileinfo			*fileinfo_create(char *path, char *filename)
{
	t_fileinfo	*info;

	if (!(info = ft_memalloc(sizeof(t_fileinfo))) ||
		!(info->filename = ft_strdup(filename)) ||
		!(info->path = path_join(path, filename)) ||
		!(info->stats = ft_memalloc(sizeof(struct stat))) ||
		lstat(info->path, info->stats) ||
		!(info->owner = ft_strdup(getpwuid(info->stats->st_uid)->pw_name)) ||
		!(info->group = ft_strdup(getgrgid(info->stats->st_gid)->gr_name)) ||
		!(info->size = ft_lltoa(info->stats->st_size)) ||
		!(info->nlink = ft_itoa(info->stats->st_nlink)))
	{
		if (info)
			fileinfo_destroy(&info);
		return (NULL);
	}
	return (fileinfo_init(info));
}

void				fileinfo_destroy(t_fileinfo **info)
{
	if ((*info)->filename)
		ft_strdel(&((*info)->filename));
	if ((*info)->path)
		ft_strdel(&((*info)->path));
	if ((*info)->size)
		ft_strdel(&((*info)->size));
	if ((*info)->nlink)
		ft_strdel(&((*info)->nlink));
	if ((*info)->link)
		ft_strdel(&((*info)->link));
	if ((*info)->owner)
		ft_strdel(&((*info)->owner));
	if ((*info)->group)
		ft_strdel(&((*info)->group));
	if ((*info)->stats)
		ft_memdel((void **)&((*info)->stats));
	ft_memdel((void **)info);
}

void				fileinfo_recursive_destroy(t_fileinfo **info)
{
	if ((*info)->right)
		fileinfo_recursive_destroy(&(*info)->right);
	if ((*info)->left)
		fileinfo_recursive_destroy(&(*info)->left);
	fileinfo_destroy(info);
}

void				fileinfo_insert(t_options *options, t_fileinfo **node,
	t_fileinfo *info)
{
	if (!*node)
		*node = info;
	else
	{
		if (options->sort(info, *node) > 0)
			fileinfo_insert(options, options->reverse ?
				&(*node)->right : &(*node)->left, info);
		else
			fileinfo_insert(options, options->reverse ?
				&(*node)->left : &(*node)->right, info);
	}
}
