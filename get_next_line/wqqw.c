/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:02:16 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 19:08:49 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	get_next_line(const int fd, char **line);

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		char *str = NULL;
		int fd = open(argv[1], O_RDONLY);
		int i;
		while ((i = get_next_line(fd, &str)) > 0)
			printf("%d %s\n", i, str);
	}
}
