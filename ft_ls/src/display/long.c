/*
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
*/
