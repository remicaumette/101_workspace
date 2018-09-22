#include "ft_container.h"

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *curr;

	while (*alst)
	{
		curr = *alst;
		*alst = (*alst)->next;		
		ft_lstdelone(&curr, del);
	}
}