/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:35:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 20:58:20 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_shell			t_shell;
typedef struct s_parser			t_parser;
typedef struct s_ast			t_ast;
typedef enum e_asttype			t_asttype;
typedef struct s_command		t_command;
typedef struct s_redirection	t_redirection;

struct						s_parser
{
	t_shell	*shell;
};

struct						s_ast
{
	t_ast	*left;
	t_ast	*right;
};

enum						e_asttype
{
	T_COMMAND,
	T_PIPELINE,
};

struct						s_command
{

};

struct						s_redirection
{};

t_parser					*parser_create(t_shell *shell);
void						parser_destroy(t_parser *parser);
int							parser_expand(t_parser *parser);
#endif
