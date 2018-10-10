/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:33:08 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 15:04:49 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
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
