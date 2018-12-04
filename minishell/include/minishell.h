/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:07:50 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 13:46:06 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <stdio.h>

typedef struct s_cmd	t_cmd;
typedef struct s_shell	t_shell;

struct					s_cmd
{
	char	*cmd;
	char	**args;
	int		status;
	t_cmd	*next;
};

struct					s_shell
{
	char	**environ;
	char	*home;
	char	*cwd;
	char	*line;
	t_cmd	*current;
};

int						shell_init(t_shell *shell, char **environ);
void					shell_destroy(t_shell *shell);
int						shell_eval(t_shell *shell);
char					*shell_getenv(t_shell *shell, char *var);

int						cmd_from_line(t_shell *shell);
void					cmd_destroy(t_cmd *cmd);

char					**plz_split_this(t_shell *shell);
#endif
