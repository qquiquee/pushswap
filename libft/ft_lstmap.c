#include "libft.h"

static t_list	*clear_list(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*trav;
	t_list	*new_lst;
	t_list	*temp;
	void	*content;

	trav = lst;
	new_lst = NULL;
	while (trav != NULL)
	{
		content = f(trav->content);
		if (content == NULL)
			return (clear_list(&new_lst, del));
		temp = ft_lstnew(content);
		if (temp == NULL)
			return (clear_list(&new_lst, del));
		ft_lstadd_front(&new_lst, temp);
		trav = trav->next;
	}
	ft_lstrev(&new_lst);
	return (new_lst);
}
