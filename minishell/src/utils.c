/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 15:33:45 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 15:33:54 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	builtin_from_name(char *cmd)
{
	if (ft_strequ("env", cmd))
		return (builtin_env);
	if (ft_strequ("cd", cmd))
		return (builtin_cd);
	if (ft_strequ("exit", cmd))
		return (builtin_exit);
	if (ft_strequ("setenv", cmd))
		return (builtin_setenv);
	if (ft_strequ("unsetenv", cmd))
		return (builtin_unsetenv);
	if (ft_strequ("echo", cmd))
		return (builtin_echo);
	return (NULL);
}

int			minishell_printerr(char *file, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

char		*ft_strjoinc(char **mot, char c)
{
	char	*tmp;
	char	m[2];

	m[0] = c;
	m[1] = 0;
	if (!(tmp = ft_strjoin(*mot, m)))
		return (NULL);
	ft_strdel(mot);
	return (*mot = tmp);
}

char		*path_join(char *path, char *filename)
{
	char	*str;
	char	*tmp;

	if (!path || !*path)
		return (ft_strdup(filename));
	if (*(path + ft_strlen(path) - 1) == '/')
		return (ft_strjoin(path, filename));
	if (!(str = ft_strnew(ft_strlen(path) + ft_strlen(filename) + 1)))
		return (NULL);
	tmp = str;
	while (*path)
		*tmp++ = *path++;
	*tmp++ = '/';
	while (*filename)
		*tmp++ = *filename++;
	return (str);
}
