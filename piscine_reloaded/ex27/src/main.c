/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:13:04 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 14:13:14 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "display_file.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		main(int argc, char **argv)
{
	char	buf[4096];
	int		fd;
	int		readed;

	if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if ((fd = open(argv[1], O_RDONLY)) != -1)
	{
		while ((readed = read(fd, buf, 4096)) > 0)
			write(1, buf, readed);
		close(fd);
	}
}
