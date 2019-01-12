/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 15:16:46 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 15:17:35 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static const char	*g_type[] = {
	"T_WORD",
	"T_NEWLINE",
	"T_PIPE",
	"T_ANDIF",
	"T_ORIF",
	"T_DSEMI",
	"T_DLESS",
	"T_DGREAT",
	"T_LESSAND",
	"T_GREATAND",
	"T_LESSGREAT",
	"T_DLESSDASH",
	"T_CLOBBER",
};

void				print_token(t_token *token)
{
	printf("token->type: %s\n", g_type[token->type]);
	printf("token->content: %s\n", token->content);
	printf("token->next: %p\n\n", token->next);
	if (token->next)
		print_token(token->next);
}

void				print_node(t_node *node)
{
	int i;

	i = -1;
	printf("node->type: %s\n", g_type[node->type]);
	printf("node->command: %p\n", node->command);
	if (node->command)
	{
		printf("node->command->name: %s\n", node->command->name);
		printf("node->command->arguments: %p\n", node->command->arguments);
		while (node->command->arguments && node->command->arguments[++i])
			printf("  - %s\n", node->command->arguments[i]);
		printf("node->command->redirection: %p\n", node->command->redirection);
	}
	printf("node->next: %p\n\n", node->next);
	if (node->next)
		print_node(node->next);
}
