/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_getenv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:53:18 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 16:53:26 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char	*shell_getenv(t_shell *shell, char *name)
{
	int		i;
	char	*delimiter;

	i = -1;
	while (shell->environment && shell->environment[++i])
		if (!(delimiter = ft_strchr(shell->environment[i], '=')))
			continue ;
		else if (ft_strnequ(shell->environment[i], name,
			delimiter - shell->environment[i]))
			return (delimiter + 1);
	return (NULL);
}
