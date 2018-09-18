void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc >= 2)
		while (argv[++i])
		{
			while (*argv[i])
				ft_putchar(*argv[i]++);
			ft_putchar('\n');
		}
}
