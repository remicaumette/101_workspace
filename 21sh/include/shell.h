/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:08:55 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 16:05:49 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include "libft.h"
# include "lexer.h"
# include "parser.h"
# include "utils.h"

typedef struct s_shell		t_shell;
typedef struct s_action		t_action;
typedef int					(*t_actionhandler)(t_shell *, char *, int);

struct						s_shell
{
	char		**environment;
	char		**history;
	char		*line;
	char		missing_token;
	t_lexer		*lexer;
	t_parser	*parser;
};

struct						s_action
{
	char			code[3];
	t_actionhandler	handler;
};

extern t_action				g_actions[];
t_shell						*g_shell;

t_shell						*shell_create(char **environment);
void						shell_destroy(t_shell *shell);
int							shell_start(t_shell *shell);
int							shell_envinit(t_shell *shell, char **default_env);
char						*shell_getenv(t_shell *shell, char *name);
char						**shell_setenv(t_shell *shell, char *name,
	char *value);
char						**shell_unsetenv(t_shell *shell, char *name);
char						*shell_gethome(t_shell *shell);
int							shell_actiondispatcher(t_shell *shell, char *buf,
	int readed);
int							shell_processline(t_shell *shell);
int							action_arrowup(t_shell *shell, char *buf,
	int readed);
int							action_basic(t_shell *shell, char *buf,
	int readed);
int							action_return(t_shell *shell, char *buf,
	int readed);

// debug
void						print_token(t_token *token);
void						print_node(t_node *node);
#endif
