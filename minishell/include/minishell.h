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
# include <sys/stat.h>
# include <dirent.h>

typedef struct s_cmd		t_cmd;
typedef struct s_shell		t_shell;
typedef struct s_word		t_word;
typedef int		(*t_builtin)(t_shell *, t_cmd *);

struct					s_cmd
{
	char	*exec;
	char	*cmd;
	char	**args;
};

struct					s_shell
{
	char	**env;
	char	*home;
	char	*line;
	t_cmd	*current;
};

struct					s_word
{
	t_shell	*shell;
	char	***words;
	char	*word;
	char	*line;
	char	*name;
	char	*env;
	char	quote;
	char	*tmp;
};

int							shell_init(t_shell *shell, char **env);
void						shell_destroy(t_shell *shell);
int							shell_eval(t_shell *shell);
char						*shell_getenv(t_shell *shell, char *name);

int							cmd_from_line(t_shell *shell);
t_cmd						*cmd_from_words(char **words);
void						cmd_destroy(t_cmd **cmd);
int							cmd_resolve_exec(t_shell *shell, t_cmd *cmd);

int							words_from_line(t_shell *shell, char ***words);

char						*process_getexec(t_shell *shell, char *file);
int							process_run(t_shell *shell, t_cmd *cmd);

int							builtin_cd(t_shell *shell, t_cmd *cmd);
int							builtin_echo(t_shell *shell, t_cmd *cmd);
int							builtin_env(t_shell *shell, t_cmd *cmd);
int							builtin_exit(t_shell *shell, t_cmd *cmd);
int							builtin_setenv(t_shell *shell, t_cmd *cmd);
int							builtin_unsetenv(t_shell *shell, t_cmd *cmd);

t_builtin					builtin_from_name(char *cmd);
int							minishell_printerr(char *file, char *msg);
char						*ft_strjoinc(char **mot, char c);
char						*path_join(char *path, char *filename);
#endif
