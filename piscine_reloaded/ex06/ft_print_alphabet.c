void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	int i;

	i = 'a' - 1;
	while (++i <= 'z')
		ft_putchar(i);
}
