/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:07:50 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 19:10:59 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"

typedef struct	s_minishell
{
	char	**environ;
}				t_minishell;

typedef struct	s_minishell_cmd
{
	char	*cmd;
	char	**arguments;
}				t_minishell_cmd;

void			minishell_init(t_minishell *minishell);
int				minishell_start(t_minishell *minishell);
int				minishell_parse_cmd(t_minishell_cmd *cmd,
					char *line);
int				minishell_run_cmd(t_minishell *minishell,
					t_minishell_cmd *cmd);

#endif
