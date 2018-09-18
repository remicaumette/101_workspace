#ifndef FT_CONTAINER_H
# define FT_CONTAINER_H
# include "ft_std.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_map
{
	void			*key;
	void			*value;
	struct s_list	*next;
}				t_map;

// linked map
// linked list
// linked queue
// linked stack
// hash map
// hash list
// hash queue
// hash stack

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem));
#endif