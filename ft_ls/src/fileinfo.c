/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fileinfo.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:27:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 18:00:28 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_fileinfo	*fileinfo_create(char *path, char *filename)
{
	t_fileinfo		*info;
	char			buf[1024];
	int				size;

	if (!(info = ft_memalloc(sizeof(t_fileinfo))) ||
		!(info->filename = ft_strdup(filename)) ||
		!(info->path = path_join(path, filename)) ||
		!(info->stats = ft_memalloc(sizeof(struct stat))) ||
		lstat(info->path, info->stats) ||
		!(info->passwd = getpwuid(info->stats->st_uid)) ||
		!(info->group = getgrgid(info->stats->st_gid)) ||
		!(info->size = ft_lltoa(info->stats->st_size)) ||
		!(info->nlink = ft_itoa(info->stats->st_nlink)))
		return (NULL);
	if (S_ISLNK(info->stats->st_mode))
	{
		size = readlink(info->path, buf, 1024);
		if (!(info->link = ft_strnew(size)))
			return (NULL);
		ft_strncpy(info->link, buf, size);
	}
	else
		info->link = NULL;
	info->left = NULL;
	info->right = NULL;
	return (info);
}

void		fileinfo_destroy(t_fileinfo **info)
{
	ft_strdel(&((*info)->filename));
	ft_strdel(&((*info)->path));
	ft_strdel(&((*info)->size));
	ft_strdel(&((*info)->nlink));
	ft_memdel((void **)&((*info)->stats));
	ft_memdel((void **)info);
}

void		fileinfo_recursive_destroy(t_fileinfo **info)
{
	if ((*info)->right)
		fileinfo_recursive_destroy(&(*info)->right);
	if ((*info)->left)
		fileinfo_recursive_destroy(&(*info)->left);
	fileinfo_destroy(info);
}

void		fileinfo_insert(t_options *options, t_fileinfo **node,
	t_fileinfo *info, sort_func cmp)
{
	if (!*node)
		*node = info;
	else
	{
		if (cmp(info, *node) > 0)
			fileinfo_insert(options, options->reverse ?
				&(*node)->right : &(*node)->left, info, cmp);
		else
			fileinfo_insert(options, options->reverse ?
				&(*node)->left : &(*node)->right, info, cmp);
	}
}

t_fileinfo	*fileinfo_last(t_fileinfo *node)
{
	if (!node->right)
		return (node);
	return (fileinfo_last(node->right));
}
