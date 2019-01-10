#include "shell.h"

static const char *type[] = {
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

void		print_token(t_token *token)
{
	printf("token->type: %s\n", type[token->type]);
	printf("token->content: %s\n", token->content);
	printf("token->next: %p\n\n", token->next);
	if (token->next)
		print_token(token->next);
}

void		print_node(t_node *node)
{
	printf("node->type: %s\n", type[node->type]);
	printf("node->command: %p\n", node->command);
	if (node->command)
	{
		printf("node->command->name: %s\n", node->command->name);
		printf("node->command->arguments: %p\n", node->command->arguments);
		for (int i = 0; node->command->arguments && node->command->arguments[i]; i++)
			printf("  - %s\n", node->command->arguments[i]);
		printf("node->command->redirection: %p\n", node->command->redirection);

	}
	printf("node->next: %p\n\n", node->next);
	if (node->next)
		print_node(node->next);
}
