/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_select.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 20:21:07 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 16:13:36 by rcaumett    ###    #+. /#+    ###.fr     */
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
# define TC_KEY_BACKSPACE	{ 32, 0, 0 }
# define TC_KEY_DELETE		{ 127, 0, 0 }
# define TC_KEY_RETURN		{ 10, 0, 0 }
# define TC_KEY_ESC			{ 27, 0, 0 }
# define TC_KEY_ARROW_UP	{ 27, 91, 65 }
# define TC_KEY_ARROW_DOWN	{ 27, 91, 66 }
# define TC_KEY_ARROW_RIGHT	{ 27, 91, 67 }
# define TC_KEY_ARROW_LEFT	{ 27, 91, 68 }

typedef struct s_select			t_select;
typedef struct s_select_entry	t_select_entry;
typedef struct winsize			t_winsize;

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

t_select						g_select;

int								select_init(t_select *select, char **args);
int								select_start(t_select *select);
int								select_render(t_select *select);
void							select_destroy(t_select *select);
t_select_entry					*select_entry_create(char *content);
void							select_entry_destroy(t_select_entry *entry);
#endif
