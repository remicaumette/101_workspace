/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 12:55:39 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:38:36 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include <stdio.h>

typedef struct s_process	t_process;

struct						s_process
{
	char	*file;
	char	*cwd;
	char	**args;
	char	**env;
	pid_t	pid;
	int		status;
	int		error;
	int		stdin[2];
	int		stdout[2];
	int		stderr[2];
};

t_process					*process_create(char *file, char **args,
	char **env);
void						process_destroy(t_process *process);
int							process_run(t_process *process);
#endif
