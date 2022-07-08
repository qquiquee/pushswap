#include "libft.h"

/*
** Deletes nodes from list if the compar function returns 0
** Using the del function
** Compare function will compare the content of the node with match
** Return the number of nodes that were deleted
**
** https://stackoverflow.com/questions/12914917
**
** head = address of the first node in the list
** compar = a comparing function
** match = data that will be compared with the content of the node
** del = delete function to be used to free the node and it's content
*/

size_t	ft_lstdelcmp(t_list **head, int (*compar)(const void *, const void *),
		void *match, void (*del)(void *))
{
	size_t	n;
	t_list	*entry;

	n = 0;
	entry = *head;
	while (entry)
	{
		if (compar(entry->content, match) == 0)
		{
			*head = entry->next;
			ft_lstdelone(entry, del);
			entry = *head;
			n++;
		}
		else
		{
			head = &entry->next;
			entry = *head;
		}
	}
	return (n);
}
