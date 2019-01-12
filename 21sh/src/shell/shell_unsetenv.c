/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_unsetenv.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:54:11 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 17:05:19 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char	**shell_unsetenv(t_shell *shell, char *name)
{
	char	len;
	char	**env;
	int		i;

	len = ft_strlen(name);
	env = NULL;
	i = -1;
	while (shell->environment && shell->environment[++i])
		if (ft_strncmp(name, shell->environment[i], len) &&
			!(env = ft_strarr_add(env, shell->environment[i])))
			return (NULL);
	ft_strarr_del(shell->environment);
	return (shell->environment = env);
}
