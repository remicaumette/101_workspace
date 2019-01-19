/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_setenv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:53:46 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 16:58:29 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

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
	while (shell->environment && shell->environment[++i])
		if (ft_strncmp(name, shell->environment[i], len) &&
			!(env = ft_strarr_add(env, shell->environment[i])))
			return (NULL);
	if (!(env = ft_strarr_add(env, tmp)))
		return (NULL);
	ft_strarr_del(shell->environment);
	return (shell->environment = env);
}
