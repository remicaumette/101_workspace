/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_params.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:10:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 14:10:30 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_sort_params(int argc, char **argv)
{
	int		i;
	int		j;
	char	*buf;

	i = argc;
	while (--i > 0)
	{
		j = 0;
		while (++j < i)
			if (ft_strcmp(argv[i], argv[j]) < 0)
			{
				buf = argv[i];
				argv[i] = argv[j];
				argv[j] = buf;
			}
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc >= 2)
	{
		ft_sort_params(argc, argv);
		while (argv[++i])
		{
			while (*argv[i])
				ft_putchar(*argv[i]++);
			ft_putchar('\n');
		}
	}
}
