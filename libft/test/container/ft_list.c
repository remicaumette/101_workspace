#include "libft.h"
#include <stdio.h>

void	print(t_list *e)
{
	printf("%lu - '%s'\n", e->content_size, (char *) e->content);
}

t_list	*map(t_list *e)
{
	t_list *new;
	
	new = ft_lstnew(e->content, e->content_size);
	ft_memset(new->content, 'o', 4);
	return (new);
}

void	del(void *data, size_t size)
{
	(void)size;
	free(data);
}

int		main(void)
{
	t_list	*list;
	t_list	*list2;

	list = NULL;
	ft_lstadd(&list, ft_lstnew("    1", 6));
	ft_lstadd(&list, ft_lstnew("    2", 6));
	ft_lstadd(&list, ft_lstnew("    3", 6));

	ft_lstiter(list, print);

	list2 = ft_lstmap(list, map);
	ft_lstiter(list2, print);

	printf("list->next->next: %p\n", list->next->next);
	printf("list->next->next->next: %p\n", list->next->next->next);
	ft_lstdelone(&(list->next->next), del);
	printf("list->next->next: %p\n", list->next->next);
	printf("list->next: %p\n", list->next);
	ft_lstdel(&list2, del);
	printf("list2: %p\n", list2);
	return (0);
}