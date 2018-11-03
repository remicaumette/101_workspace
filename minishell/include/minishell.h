/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:07:50 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 05:00:55 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"

# include <stdio.h>
typedef struct	s_minishell
{
	char	**environ;
}				t_minishell;

typedef struct	s_command
{
	char	*cmd;
	char	**arguments;
}				t_command;

int				command_parse(t_minishell *minishell,
					t_command *command, char *line);

int				minishell_init(t_minishell *minishell, char **environ);
int				minishell_start(t_minishell *minishell);
#endif
