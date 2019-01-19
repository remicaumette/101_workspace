/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_create.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 12:51:03 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:50:33 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_process	*process_create(char *file, char **args, char **env)
{
	t_process	*process;

	if (!(process = ft_memalloc(sizeof(t_process))) ||
		!(process->file = ft_strdup(file)) ||
		pipe(process->stdin) == -1 ||
		pipe(process->stdout) == -1 ||
		pipe(process->stderr) == -1)
		return (NULL);
	process->args = ft_strarr_clone(args);
	process->env = ft_strarr_clone(env);
	process->error = 0;
	process->status = -1;
	process->pid = -1;
	return (process);
}
