int	ft_iterative_factorial(int nb)
{
	int result;

	if (0 > nb || nb > 12)
		return (0);
	result = 1;
	while (nb)
		if (nb <= 1)
			result *= nb-- || 1;
		else
			result *= nb--;
	return (result);
}

