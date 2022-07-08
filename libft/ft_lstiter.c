#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*trav;

	trav = lst;
	while (trav != NULL)
	{
		f(trav->content);
		trav = trav->next;
	}
}
