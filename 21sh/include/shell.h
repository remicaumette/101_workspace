/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:08:55 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 16:00:21 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include "libft.h"
# include "lexer.h"
# include "parser.h"
# include "process.h"
# include "utils.h"
# include "tc_key.h"

typedef struct s_shell		t_shell;
typedef struct s_action		t_action;
typedef struct s_line		t_line;
typedef struct s_history	t_history;
typedef struct s_histentry	t_histentry;
typedef struct winsize		t_winsize;
typedef int					(*t_actionhandler)(t_shell *);

struct						s_shell
{
	char		**environment;
	char		missing_token;
	t_line		*line;
	t_history	*history;
	t_lexer		*lexer;
	t_parser	*parser;
};

struct						s_action
{
	char			code[3];
	t_actionhandler	handler;
};

struct						s_line
{
	char		*content;
	int			size;
	int			cursor;
	t_winsize	window;
};

struct						s_history
{
	int			size;
	t_histentry	*begin;
	t_histentry	*curr;
	t_histentry	*end;
};

struct						s_histentry
{
	t_histentry	*prev;
	char		*content;
	t_histentry	*next;
};

extern t_action				g_actions[];
t_shell						*g_shell;

t_shell						*shell_create(char **environment);
void						shell_destroy(t_shell *shell);
int							shell_start(t_shell *shell);
int							shell_actiondispatcher(t_shell *shell, char *buf,
	int readed);
int							shell_processline(t_shell *shell);
int							shell_prompt(t_shell *shell);
int							shell_envinit(t_shell *shell, char **default_env);
char						*shell_getenv(t_shell *shell, char *name);
char						**shell_setenv(t_shell *shell, char *name,
	char *value);
char						**shell_unsetenv(t_shell *shell, char *name);
char						*shell_gethome(t_shell *shell);

t_history					*history_create(void);
void						history_destroy(t_history *history);
t_histentry					*histentry_create(char *content);
void						histentry_destroy(t_histentry *entry);
t_histentry					*history_insert(t_history *history, char *line);

t_line						*line_create(void);
void						line_destroy(t_line **line);
void						line_reset(t_line *line);
int							line_inser(t_line *line, char c);
int							line_deltoend(t_line *line);
int							line_backdel(t_line *line);
void						line_replace(t_line *line, char *src);

int							action_return(t_shell *shell);
int							action_clear(t_shell *shell);
int							action_clear_to_end(t_shell *shell);
int							action_backdel(t_shell *shell);
int							action_hist_up(t_shell *shell);
int							action_hist_down(t_shell *shell);
int							action_move_up(t_shell *shell);
int							action_move_down(t_shell *shell);
int							action_move_left(t_shell *shell);
int							action_move_right(t_shell *shell);
int							action_move_first(t_shell *shell);
int							action_move_end(t_shell *shell);
int							action_move_next_word(t_shell *shell);
int							action_move_prev_word(t_shell *shell);
int							action_stop(t_shell *shell);

void						print_token(t_token *token);
void						print_node(t_node *node);
#endif
