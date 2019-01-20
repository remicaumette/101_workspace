/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_select.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 20:21:07 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 19:15:20 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# define TC_KEY_ESPACE		{ 32, 0, 0, 0 }
# define TC_KEY_BACKSPACE	{ 127, 0, 0, 0 }
# define TC_KEY_DELETE		{ 27, 91, 51, 126 }
# define TC_KEY_RETURN		{ 10, 0, 0, 0 }
# define TC_KEY_ESC			{ 27, 0, 0, 0 }
# define TC_KEY_ARROW_UP	{ 27, 91, 65, 0 }
# define TC_KEY_ARROW_DOWN	{ 27, 91, 66, 0 }
# define TC_KEY_ARROW_RIGHT	{ 27, 91, 67, 0 }
# define TC_KEY_ARROW_LEFT	{ 27, 91, 68, 0 }

typedef struct s_select			t_select;
typedef struct s_select_entry	t_select_entry;
typedef struct s_select_action	t_select_action;
typedef struct winsize			t_winsize;
typedef int						(*t_select_action_handler)(t_select *);

struct							s_select
{
	int				x;
	int				y;
	int				count;
	int				max_length;
	t_winsize		window;
	t_select_entry	*entry;
};

struct							s_select_entry
{
	char			*content;
	int				selected;
	t_select_entry	*next;
};

struct							s_select_action
{
	char					key[4];
	t_select_action_handler	handler;
};

t_select						g_select;

int								select_init(t_select *select, char **args);
int								select_start(t_select *select);
int								select_render(t_select *select);
int								select_action_dispatcher(t_select *select, char *buf);
void							select_destroy(t_select *select);
t_select_entry					*select_entry_create(char *content);
t_select_entry					*select_entry_at(t_select *select, int x, int y);
void							select_entry_destroy(t_select_entry *entry);

int								action_arrow_down(t_select *select);
int								action_arrow_left(t_select *select);
int								action_arrow_right(t_select *select);
int								action_arrow_up(t_select *select);
int								action_backspace(t_select *select);
int								action_esc(t_select *select);
int								action_espace(t_select *select);
int								action_return(t_select *select);
#endif
