#include "ft_container.h"

t_list	*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list	*head;
	t_list	*curr;

	if (!lst)
		return (NULL);
	head = f(lst);
	curr = head;
	while (lst->next)
	{
		lst = lst->next;
		if ((curr->next = f(lst)) == NULL)
			return (NULL);
		curr = curr->next;
	}
	return (head);
}