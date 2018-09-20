#include "ft_container.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*list;

	if (*alst)
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}	
	else
		*alst = new;
}
