#include "../../include/push_swap.h"

void	print_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	printf("lista\n");
	while (i < size)
	{
		printf("  %d\n", tab[i]);
		i++;
	}
}

void	ft_error(t_data *data)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_all(data);
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

void	print_stacks(t_data data)
{
	int	i;

	i = 0;
	printf("Stack a: ");
	while (i < data.size_a)
	{
		printf("%d ", data.stack_a[i]);
		i++;
	}
	i = 0;
	printf("\nStack b: ");
	while (i < data.size_b)
	{
		printf("%d ", data.stack_b[i]);
		i++;
	}
	printf("\n");
}

/*
void	print_stacks(t_data data)
{
	int	i;

	i = 0;
	printf("\tStack a\t\tStack b\n");
	while (i < data.size_a && i < data.size_b)
	{
		printf("\t   %d\t\t   %d\n", data.stack_a[i], data.stack_b[i]);
		i++;
	}
	if (data.size_a > data.size_b)
	{
		while (i < data.size_a)
		{
			printf("\t   %d\n", data.stack_a[i]);
			i++;
		}
	}
	else
	{
		while (i < data.size_b)
		{
			printf("\t\t\t   %d\n", data.stack_b[i]);
			i++;
		}
	}
}
*/
void	free_all(t_data *data)
{
	free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
	free(data->a_sorted);
	free(data->sorted);
	if (data->sizes)
		free(data->sizes);
}
