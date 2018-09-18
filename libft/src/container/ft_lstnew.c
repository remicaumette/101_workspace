#include "ft_container.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((list = (t_list *) ft_memalloc(sizeof(*list))) == NULL)
		return (NULL);
	list->content = content;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}