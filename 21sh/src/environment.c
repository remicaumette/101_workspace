/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 16:44:32 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 21:35:24 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char	*shell_getenv(t_shell *shell, char *name)
{
	int		i;
	char	*delimiter;

	i = -1;
	while (shell->environment[++i])
		if (!(delimiter = ft_strchr(shell->environment[i], '=')))
			continue ;
		else if (ft_strnequ(shell->environment[i], name,
			delimiter - shell->environment[i]))
			return (delimiter + 1);
	return (NULL);
}

char	**shell_setenv(t_shell *shell, char *name, char *value)
{
	char	len;
	char	tmp[ft_strlen(name) + ft_strlen(value) + 1];
	char	**env;
	int		i;

	len = ft_strlen(name);
	ft_strcpy(tmp, name);
	*(tmp + len) = '=';
	ft_strcat(tmp, value);
	env = NULL;
	i = -1;
	while (shell->environment[++i])
		if (ft_strncmp(name, shell->environment[i], len) &&
			!(env = ft_strarr_add(env, shell->environment[i])))
			return (NULL);
	if (!(env = ft_strarr_add(env, tmp)))
		return (NULL);
	ft_strarr_del(shell->environment);
	return (shell->environment = env);
}

char	**shell_unsetenv(t_shell *shell, char *name)
{
	char	len;
	char	**env;
	int		i;

	len = ft_strlen(name);
	env = NULL;
	i = -1;
	while (shell->environment[++i])
		if (ft_strncmp(name, shell->environment[i], len) &&
			!(env = ft_strarr_add(env, shell->environment[i])))
			return (NULL);
	ft_strarr_del(shell->environment);
	return (shell->environment = env);
}

char	*shell_gethome(t_shell *shell)
{
	char	*home;

	home = shell_getenv(shell, "HOME");
	return (home ? home : "/");
}
