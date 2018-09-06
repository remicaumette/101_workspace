int	ft_sqrt(int nb)
{
	int n;

	if (nb <= 1)
		return (nb == 1);
	n = 2;
	while (n < nb)
		if (nb % n == 0)
			return (n);
		else
			n >>= 2;
	return (0);
}

