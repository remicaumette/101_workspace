/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_envinit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:53:00 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 14:33:31 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	init_path(t_shell *shell)
{
	int		fd;
	char	*line;
	char	**paths;

	paths = NULL;
	if ((fd = open("/etc/paths", O_RDONLY)) == -1)
		return (1);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(paths = ft_strarr_add(paths, line)))
			return (1);
		ft_strdel(&line);
	}
	if (!paths || !(line = ft_strarr_join(paths, ":")))
		return (1);
	shell_setenv(shell, "PATH", line);
	ft_strdel(&line);
	ft_strarr_del(paths);
	return (0);
}

int			shell_envinit(t_shell *shell, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (!(shell->environment = ft_strarr_add(shell->environment, env[i])))
			return (1);
	if (!(shell_getenv(shell, "PATH")) && init_path(shell))
		return (1);
	return (0);
}
