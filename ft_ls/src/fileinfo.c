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

void		fileinfo_insert(t_fileinfo **node, t_fileinfo *info,
	int cmp(t_fileinfo *f1, t_fileinfo *f2))
{
	if (!*node)
		*node = info;
	else if (cmp(info, *node) > 0)
		fileinfo_insert(&(*node)->left, info, cmp);
	else
		fileinfo_insert(&(*node)->right, info, cmp);
}

t_fileinfo	*fileinfo_last_right(t_fileinfo *node)
{
	if (!node->right)
		return (node);
	return (fileinfo_last_right(node->right));
}

t_fileinfo	*fileinfo_last_left(t_fileinfo *node)
{
	if (!node->left)
		return (node);
	return (fileinfo_last_left(node->left));
}

void	debug_file(t_fileinfo *info)
{
	printf("t_fileinfo {\n");
	printf("\tfilename = '%s'\n", info->filename);
	printf("\tpermissions = '%s'\n", info->permissions);
	printf("\tnlink = %d\n", info->nlink);
	printf("\tsnlink = '%s'\n", info->snlink);
	printf("\tuser = '%s'\n", info->user);
	printf("\tgroup = '%s'\n", info->group);
	printf("\tsize = %lld\n", info->size);
	printf("\tssize = '%s'\n", info->ssize);
	printf("}\n");
}