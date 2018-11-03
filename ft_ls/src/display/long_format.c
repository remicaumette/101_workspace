/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   long_format.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 15:34:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 02:38:58 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	stradd_formatted(char *str, char *content, int *cursor, int width)
{
	int	i;

	i = -1;
	while (width != -1 && ++i < (width - (int)ft_strlen(content)))
		str[(*cursor)++] = ' ';
	str += *cursor;
	while (*content)
	{
		*str++ = *content++;
		(*cursor)++;
	}
}

static void	parse_permissions(t_fileinfo *file, char *str, int *cursor)
{
	str[(*cursor)++] = get_file_type(file->stats);
	str[(*cursor)++] = (file->stats->st_mode & S_IRUSR) ? 'r' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IWUSR) ? 'w' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IXUSR) ? 'x' : '-';
	str[*cursor - 1] = (file->stats->st_mode & S_ISUID) ? 'S'
		: str[*cursor - 1];
	str[(*cursor)++] = (file->stats->st_mode & S_IRGRP) ? 'r' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IWGRP) ? 'w' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IXGRP) ? 'x' : '-';
	str[*cursor - 1] = (file->stats->st_mode & S_ISGID) ? 'S'
		: str[*cursor - 1];
	str[(*cursor)++] = (file->stats->st_mode & S_IROTH) ? 'r' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IWOTH) ? 'w' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IXOTH) ? 'x' : '-';
	str[*cursor - 1] = (file->stats->st_mode & S_ISVTX) ? 'T'
		: str[*cursor - 1];
}

static void	parse_date(t_fileinfo *file, char *str, int *cursor)
{
	char	**tmp;
	int		i;

	if (!(tmp = ft_strsplit(ctime(&file->stats->st_mtime), ' ')))
		exit(1);
	stradd_formatted(str, tmp[1], cursor, 4);
	stradd_formatted(str, tmp[2], cursor, 3);
	str[(*cursor)++] = ' ';
	i = -1;
	if (time(NULL) - file->stats->st_mtime > 15768000)
	{
		str[(*cursor)++] = ' ';
		while (++i < 4)
			str[(*cursor)++] = tmp[4][i];
	}
	else
		while (++i < 5)
			str[(*cursor)++] = tmp[3][i];
	i = -1;
	while (tmp[++i])
		ft_strdel(&tmp[i]);
	free(tmp);
}

static int	get_size(t_options *options, t_dirinfo *dir, t_fileinfo *file)
{
	(void)options;
	return (34 + dir->link_width + dir->user_width + dir->group_width +
		dir->size_width + ft_strlen(file->filename) +
		(file->link ? (ft_strlen(file->link) + 4) : 0) +
		(options->slash && S_ISDIR(file->stats->st_mode)));
}

void		long_format_display(t_options *options, t_dirinfo *dir,
	t_fileinfo *file, t_fileinfo *last)
{
	int		cursor;
	char	str[get_size(options, dir, file)];

	(void)last;
	cursor = 0;
	parse_permissions(file, str, &cursor);
	stradd_formatted(str, file->nlink, &cursor, dir->link_width + 2);
	stradd_formatted(str, file->owner, &cursor, dir->user_width + 1);
	stradd_formatted(str, file->group, &cursor, dir->group_width + 2);
	stradd_formatted(str, file->size, &cursor, dir->size_width + 2);
	parse_date(file, str, &cursor);
	str[cursor++] = ' ';
	stradd_formatted(str, file->filename, &cursor, -1);
	if (options->slash && S_ISDIR(file->stats->st_mode))
		str[cursor++] = '/';
	if (file->link)
	{
		stradd_formatted(str, " -> ", &cursor, -1);
		stradd_formatted(str, file->link, &cursor, -1);
	}
	str[cursor++] = '\n';
	str[cursor] = 0;
	ft_putstr(str);
}
