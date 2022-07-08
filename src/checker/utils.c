#include "../../include/checker.h"

void	del_first_node(t_list **list)
{
	t_list	*temp;

	temp = *list;
	*list = (*list)->next;
	free(temp);
}

void	del_last_node(t_list **list)
{
	t_list	*temp;

	temp = *list;
	while ((*list)->next->next)
		*list = (*list)->next;
	free((*list)->next);
	(*list)->next = NULL;
	*list = temp;
}

void	free_list(t_list **list)
{
	while ((*list)->next)
	{
		free(*list);
		*list = (*list)->next;
	}
	free(*list);
}

void	free_all(t_data *data)
{
	free(data->args);
	if (data->stack_a)
		free_list(&data->stack_a);
	if (data->stack_b)
		free_list(&data->stack_b);
	if (data->line)
		free(data->line);
}

void	check_order(t_data data)
{
	t_list	*list;

	list = data.stack_a;
	if (data.size == ft_lstsize(list))
	{
		while (list->next)
		{
			if (*((int *)(list->content)) > *((int *)(list->next->content)))
			{
				printf("KO\n");
				return ;
			}
			list = list->next;
		}
		printf("OK\n");
	}
	else
		printf("KO\n");
}
