#include "../../include/checker.h"

void	print_content(void *content)
{
	int	num;

	num = *((int *)content);
	printf("\t  %d\n", num);
}

void	print_stacks(t_list *list1, t_list *list2)
{
	printf("\tStack a\t\tStack b\n");
	while (list1 || list2)
	{
		if (list1 && list2)
		{
			printf("\t   %d\t\t   %d\n", *((int *)(list1->content)),
				*((int *)(list2->content)));
			list1 = list1->next;
			list2 = list2->next;
		}
		else if (list1)
		{
			printf("\t   %d\n", *((int *)(list1->content)));
			list1 = list1->next;
		}
		else if (list2)
		{
			printf("\t\t\t   %d\n", *((int *)(list2->content)));
			list2 = list2->next;
		}
	}
}

void	ft_error(t_data *data)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (data->args != NULL)
		free(data->args);
	exit(EXIT_FAILURE);
}

long	ft_atol(const char *str)
{
	long	neg;
	long	num;
	int		i;

	i = 0;
	neg = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		neg *= -1;
		i++;
	}
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}
