/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   long_format.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 16:13:56 by sifouche     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:09:14 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	parse_permissions(t_fileinfo *file, char *str, int *cursor)
{
	str[(*cursor)++] = file_type(file->stats);
	str[(*cursor)++] = (file->stats->st_mode & S_IRUSR) ? 'r' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IWUSR) ? 'w' : '-';
	if (file->stats->st_mode & S_IXUSR && file->stats->st_mode & S_ISUID)
		str[(*cursor)++] = 's';
	else if (file->stats->st_mode & S_ISUID)
		str[(*cursor)++] = 'S';
	else
		str[(*cursor)++] = (file->stats->st_mode & S_IXUSR) ? 'x' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IRGRP) ? 'r' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IWGRP) ? 'w' : '-';
	if (file->stats->st_mode & S_IXGRP && file->stats->st_mode & S_ISGID)
		str[(*cursor)++] = 's';
	else if (file->stats->st_mode & S_ISGID)
		str[(*cursor)++] = 'S';
	else
		str[(*cursor)++] = (file->stats->st_mode & S_IXGRP) ? 'x' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IROTH) ? 'r' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IWOTH) ? 'w' : '-';
	if (file->stats->st_mode & S_IXOTH && file->stats->st_mode & S_ISVTX)
		str[(*cursor)++] = 't';
	else if (file->stats->st_mode & S_ISVTX)
		str[(*cursor)++] = 'T';
	else
		str[(*cursor)++] = (file->stats->st_mode & S_IXOTH) ? 'x' : '-';
}

static void	parse_date(t_fileinfo *file, char *str, int *cursor)
{
	char	**tmp;
	int		i;

	if (!(tmp = ft_strsplit(ctime(&file->stats->st_mtime), ' ')))
		exit(1);
	stradd_formatted_left(str, tmp[1], cursor, 4);
	stradd_formatted_left(str, tmp[2], cursor, 3);
	str[(*cursor)++] = ' ';
	i = -1;
	if (time(NULL) - file->stats->st_mtime > 15768000 ||
		time(NULL) - file->stats->st_mtime < -15768000)
	{
		str[(*cursor)++] = ' ';
		while (++i < (int)(ft_strlen(tmp[4]) - 1))
			str[(*cursor)++] = tmp[4][i];
	}
	else
		while (++i < 5)
			str[(*cursor)++] = tmp[3][i];
	ft_strarr_del(tmp);
}

static char	get_xattr(t_fileinfo *file)
{
	int			xattr;
	acl_t		acl;
	acl_entry_t	entry;

	xattr = listxattr(file->path, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_link_np(file->path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &entry) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		return ('@');
	else if (acl != NULL)
	{
		acl_free(acl);
		return ('+');
	}
	return (' ');
}

static void	display_file(t_ls *ls, t_fileinfo *file)
{
	int		cursor;
	char	str[120 + ls->dir.filename_width + ft_strlen(file->link)];

	cursor = 0;
	parse_permissions(file, str, &cursor);
	str[cursor++] = get_xattr(file);
	stradd_formatted_left(str, file->nlink, &cursor, ls->dir.link_width + 1);
	str[cursor++] = ' ';
	stradd_formatted_right(str, file->owner, &cursor, ls->dir.user_width + 2);
	stradd_formatted_right(str, file->group, &cursor, ls->dir.group_width + 2);
	file->minor ? stradd_formatted_left(str, file->size, &cursor, 3) : 0;
	file->minor ? str[cursor++] = ',' : 0;
	file->minor ? str[cursor++] = ' ' : 0;
	file->minor ? stradd_formatted_left(str, file->minor, &cursor, 3) :
		stradd_formatted_left(str, file->size, &cursor, ls->dir.size_width);
	parse_date(file, str, &cursor);
	str[cursor++] = ' ';
	stradd_formatted_left(str, *ls->dir.path ?
		file->filename : file->path, &cursor, -1);
	ls->slash && S_ISDIR(file->stats->st_mode) ? str[cursor++] = '/' : 0;
	file->link ? stradd_formatted_left(str, " -> ", &cursor, -1) : 0;
	file->link ? stradd_formatted_left(str, file->link, &cursor, -1) : 0;
	str[cursor++] = '\n';
	str[cursor] = 0;
	ft_putstr(str);
}

void		long_format_display(t_ls *ls)
{
	t_fileinfo	*file;

	file = ls->dir.files;
	if (file && *ls->dir.path)
	{
		ft_putstr("total ");
		ft_putnbr(ls->dir.total);
		ft_putstr("\n");
	}
	while (file)
	{
		display_file(ls, file);
		file = file->next;
	}
}
