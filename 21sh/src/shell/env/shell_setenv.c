/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_setenv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:53:46 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 15:28:24 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char	**shell_setenv(t_shell *shell, char *name, char *value)
{
	char	*tmp;
	char	**env;
	int		len;
	int		i;

	if (!(tmp = ft_strnew(ft_strlen(name) + ft_strlen(value) + 1)))
		return (NULL);
	len = ft_strlen(name);
	ft_strcpy(tmp, name);
	*(tmp + len) = '=';
	i = -1;
	while (value && value[++i])
		*(tmp + len + i + 1) = value[i];
	env = NULL;
	i = -1;
	while (shell->environment && shell->environment[++i])
		if (ft_strncmp(name, shell->environment[i], len) &&
			!(env = ft_strarr_add(env, shell->environment[i])))
			return (NULL);
	if (!(env = ft_strarr_add(env, tmp)))
		return (NULL);
	ft_strarr_del(shell->environment);
	ft_strdel(&tmp);
	return (shell->environment = env);
}
