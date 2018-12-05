/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shelltte.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:07:50 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 14:04:08 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <stdio.h>

typedef struct s_cmd		t_cmd;
typedef struct s_shell		t_shell;

struct					s_cmd
{
	char	*cmd;
	char	**args;
	int		status;
	t_cmd	*next;
};

struct					s_shell
{
	char	**env;
	char	*home;
	char	*line;
	t_cmd	*current;
};

int							shell_init(t_shell *shell, char **env);
void						shell_destroy(t_shell *shell);
int							shell_eval(t_shell *shell);
char						*shell_getenv(t_shell *shell, char *name);
int							shell_setenv(t_shell *shell, char *value);

int							cmd_from_line(t_shell *shell);
t_cmd						*cmd_from_words(char **words);
void						cmd_destroy(t_cmd *cmd);

int							words_from_line(t_shell *shell, char ***words);
#endif
