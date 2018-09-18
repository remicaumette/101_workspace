int	ft_sqrt(int nb)
{
	int sol;

	if (nb <= 0)
		return (0);
	sol = 1;
	while (sol * sol < nb)
		sol++;
	if (sol * sol == nb)
		return (sol);
	else
		return (0);
}
