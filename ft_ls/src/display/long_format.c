#include "ft_ls.h"

static void	stradd_formatted(char *str, char *content, int *cursor, int width)
{
	int i;

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
	if (S_ISDIR(file->stats->st_mode))
		str[(*cursor)++] = 'd';
	else if (S_ISLNK(file->stats->st_mode))
		str[(*cursor)++] = 'l';
	else
		str[(*cursor)++] = '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IRUSR) ? 'r' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IWUSR) ? 'w' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IXUSR) ? 'x' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IRGRP) ? 'r' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IWGRP) ? 'w' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IXGRP) ? 'x' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IROTH) ? 'r' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IWOTH) ? 'w' : '-';
	str[(*cursor)++] = (file->stats->st_mode & S_IXOTH) ? 'x' : '-';
}

static void parse_date(t_fileinfo *file, char *str, int *cursor)
{
	char	**tmp;
	int		i;

	// tmp[4] == annee si + 6 mois
	if (!(tmp = ft_strsplit(ctime(&file->stats->st_mtime), ' ')))
		exit(1);
	stradd_formatted(str, tmp[2], cursor, 3);
	stradd_formatted(str, tmp[1], cursor, 4);
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
	ft_memdel((void **)tmp);
}

static void	print_line(t_options *options, t_dirinfo *dir, t_fileinfo *file)
{
	char		str[34 + dir->link_width + dir->user_width + dir->group_width
		+ dir->size_width + ft_strlen(file->filename) +
		(file->link ? (ft_strlen(file->link) + 4) : 0)];
	int			cursor;

	(void)options;
	cursor = 0;
	parse_permissions(file, str, &cursor);
	stradd_formatted(str, file->nlink, &cursor, dir->link_width + 2);
	stradd_formatted(str, file->passwd->pw_name, &cursor, dir->user_width + 1);
	stradd_formatted(str, file->group->gr_name, &cursor, dir->group_width + 2);
	stradd_formatted(str, file->size, &cursor, dir->size_width + 2);
	parse_date(file, str, &cursor);
	str[cursor++] = ' ';
	stradd_formatted(str, file->filename, &cursor, -1);
	if (file->link)
	{
		stradd_formatted(str, " -> ", &cursor, -1);
		stradd_formatted(str, file->link, &cursor, -1);
	}
	str[cursor++] = '\n';
	str[cursor] = 0;
	ft_putstr(str);
}

void		long_format_display(t_options *options, t_dirinfo *dir, t_fileinfo *file)
{
	if (file->right)
		long_format_display(options, dir, file->right);
	print_line(options, dir, file);
	if (file->left)
		long_format_display(options, dir, file->left);
}
