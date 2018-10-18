/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:26:40 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 16:15:57 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			parse_permissions(t_fileinfo *info, struct stat *stat)
{
	char	*s;

	if (!(s = ft_strnew(10)))
		return (0);
	if (stat->st_mode & S_IFDIR)
		s[0] = 'd';
	else if (stat->st_mode & S_IFLNK)
		s[0] = 'l';
	else
		s[0] = '-';
	s[1] = (stat->st_mode & S_IRUSR) ? 'r' : '-';
	s[2] = (stat->st_mode & S_IWUSR) ? 'w' : '-';
	s[3] = (stat->st_mode & S_IXUSR) ? 'x' : '-';
	s[4] = (stat->st_mode & S_IRGRP) ? 'r' : '-';
	s[5] = (stat->st_mode & S_IWGRP) ? 'w' : '-';
	s[6] = (stat->st_mode & S_IXGRP) ? 'x' : '-';
	s[7] = (stat->st_mode & S_IROTH) ? 'r' : '-';
	s[8] = (stat->st_mode & S_IWOTH) ? 'w' : '-';
	s[9] = (stat->st_mode & S_IXOTH) ? 'x' : '-';
	info->permissions = s;
	return (1);
}

int			parse_date(t_fileinfo *info, struct stat *stat)
{
	char	*tmp;

	tmp = ctime(&stat->st_ctime);
	(void)info;
	return (1);
}

static void			parse_flag(t_flags *flags, char c)
{
	if (c == 't')
		flags->sort = sort_time;
	else if (c == 'S')
		flags->sort = sort_size;
	else if (c == 'r')
		flags->reverse = 1;
	else if (c == 'R')
		flags->recursive = 1;
	else if (c == 'a')
		flags->hidden = 1;
	else if (c == 'l')
		flags->display = long_format;
	else if (c == '1')
		flags->display = one_per_line;
	else if (c == 'C')
		flags->display = many_per_line;
	else if (c == 'm')
		flags->display = with_commas;
	else
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd("\nusage: ft_ls [-trRlaC1] [file ...]\n", 2);
		exit(1);
	}
}

t_flags				*parse_flags(char **argv)
{
	t_flags	*flags;
	int		i;
	int		j;

	if (!(flags = ft_memalloc(sizeof(t_flags))))
		return (NULL);
	flags->display = vertical;
	flags->hidden = 0;
	flags->recursive = 0;
	flags->reverse = 0;
	flags->sort = sort_name;
	i = 0;
	while (argv[++i])
	{
		j = 0;
		if (argv[i][j] != '-')
			break ;
		while (argv[i][++j])
			parse_flag(flags, argv[i][j]);
	}
	return (flags);
}
