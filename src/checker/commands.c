#include "../../include/checker.h"

int	swap(t_list **list)
{
	t_list	*temp;

	if (ft_lstsize(*list) < 2)
		return (1);
	temp = (*list)->next;
	(*list)->next = (*list)->next->next;
	ft_lstadd_front(list, temp);
	return (1);
}

int	push(t_list **list_a, t_list **list_b)
{
	if (!*list_a)
		return (1);
	if (!*list_b)
		*list_b = ft_lstnew((*list_a)->content);
	else
		ft_lstadd_front(list_b, ft_lstnew((*list_a)->content));
	del_first_node(list_a);
	return (1);
}

int	rotate(t_list **list)
{
	if (ft_lstsize(*list) < 2)
		return (1);
	ft_lstadd_back(list, ft_lstnew((*list)->content));
	del_first_node(list);
	return (1);
}

int	reverse_rotate(t_list **list)
{
	if (ft_lstsize(*list) < 2)
		return (1);
	ft_lstadd_front(list, ft_lstnew((ft_lstlast(*list))->content));
	del_last_node(list);
	return (1);
}
