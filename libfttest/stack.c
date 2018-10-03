#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_stack *stack = NULL;
	
	ft_stack_push(&stack, ft_strdup("hello"));
	ft_stack_push(&stack, ft_strdup("world"));

	printf("%d\n", ft_stack_size(stack));
	printf("%s\n", ft_stack_pop(&stack));
	printf("%s\n", ft_stack_peek(stack));
	printf("%s\n", ft_stack_pop(&stack));
	printf("%s\n", ft_stack_pop(&stack));
	printf("%s\n", ft_stack_pop(&stack));

	ft_stack_push(&stack, ft_strdup("hello"));
	ft_stack_push(&stack, ft_strdup("world"));

	ft_stack_destroy(&stack, free);
	printf("%p\n", stack);
}
