int	ft_recursive_factorial(int nb)
{
	if (nb <= 1 || nb > 12)
		return (nb >= 0 && nb <= 12);
	return (ft_recursive_factorial(nb - 1) * nb);
}

