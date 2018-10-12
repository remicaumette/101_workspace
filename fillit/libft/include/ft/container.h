#ifndef CONTAINER_H
# define CONTAINER_H
# include "std.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_stack
{
	void			*content;
	struct s_stack	*next;
}				t_stack;

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *list);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_stack	*ft_stack_push(t_stack **begin, void *content);
void	*ft_stack_pop(t_stack **begin);
void	*ft_stack_peek(t_stack *begin);
void	ft_stack_destroy(t_stack **begin, void (*del)(void *));
int		ft_stack_size(t_stack *stack);
#endif
