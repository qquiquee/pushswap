#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*trav;

	trav = lst;
	if (trav == NULL)
		return (trav);
	while (trav->next != NULL)
		trav = trav->next;
	return (trav);
}
