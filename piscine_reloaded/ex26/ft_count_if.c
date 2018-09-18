int	ft_count_if(char **tab, int (*f)(char *))
{
	int i;
	int r;

	i = -1;
	r = 0;
	while (tab[++i])
		r += f(tab[i]) && 1;
	return (r);
}
