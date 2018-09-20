#include "ft_container.h"

t_list	*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list	*head;
	t_list	*curr;
	t_list	*tmp;

	head = NULL;
	while (lst)
	{
		if ((tmp = f(lst)) == NULL)
			return (NULL);
		if (curr)
			curr->next = tmp;
		curr = tmp;
		if (!head)
			head = curr;
		lst = lst->next;
	}
	return (head);
}