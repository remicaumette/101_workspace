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

t_fileinfo	*fileinfo_create(char *filename)
{
	t_fileinfo		*info;
	struct stat		*stats;
	struct passwd	*passwd;
	struct group	*group;

	if (!(info = ft_memalloc(sizeof(t_fileinfo))) ||
		!(info->filename = ft_strdup(filename)) ||
		!(stats = ft_memalloc(sizeof(struct stat))) || stat(filename, stats) ||
		!(passwd = getpwuid(stats->st_uid)) ||
		!(group = getgrgid(stats->st_gid)) ||
		!parse_permissions(info, stats) || !parse_date(info, stats) ||
		!(info->ssize = ft_lltoa(stats->st_size)) ||
		!(info->snlink = ft_itoa(stats->st_nlink)) ||
		!(info->user = ft_strdup(passwd->pw_name)) ||
		!(info->group = ft_strdup(group->gr_name)))
		return (NULL);
	info->filename = filename;
	info->left = NULL;
	info->right = NULL;
	info->nlink = stats->st_nlink;
	info->size = stats->st_size;
	ft_memdel((void **)&stats);
	return (info);
}

void		fileinfo_destroy(t_fileinfo **info)
{
	ft_strdel(&((*info)->filename));
	ft_strdel(&((*info)->permissions));
	ft_strdel(&((*info)->user));
	ft_strdel(&((*info)->group));
	ft_strdel(&((*info)->ssize));
	ft_strdel(&((*info)->snlink));
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

void		fileinfo_insert(t_fileinfo **node, t_fileinfo *info)
{
	if (!*node)
		*node = info;
	else if (sort_by_name(info, *node) > 0)
		fileinfo_insert(&(*node)->left, info);
	else
		fileinfo_insert(&(*node)->right, info);
	/*
	else if (info->size < (*node)->size)
		fileinfo_insert(&(*node)->left, info);
	else if (info->size > (*node)->size)
		fileinfo_insert(&(*node)->right, info);
	else if (info->size == (*node)->size)
	{
		if (ft_strcmp(info->filename, (*node)->filename) > 0)
			fileinfo_insert(&(*node)->left, info);
		else
			fileinfo_insert(&(*node)->right, info);
	}*/
}
