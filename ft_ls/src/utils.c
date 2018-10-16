#include "ft_ls.h"

char	*get_permissions(struct stat *stat)
{
	char	*s;

	if (!(s = ft_strnew(10)))
		return (NULL);
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
	return (s);
}

char	*get_date(struct stat *stat)
{
	char	*tmp;
	//char	*s;

	tmp = ctime(&stat->st_ctime);

	return (tmp);
}
