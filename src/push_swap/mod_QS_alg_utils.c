#include "../../include/push_swap.h"

void	init_extr(t_data *data, t_extr *extr, int stack)
{
	if (stack == 1)
	{
		extr->min = find_min(data->stack_a, data->size_a);
		extr->min_2 = find_second_min(data->stack_a, data->size_a);
		extr->max = find_max(data->stack_a, data->size_a);
		extr->max_2 = find_second_max(data->stack_a, data->size_a);
	}
	else
	{
		extr->min = find_min(data->stack_b, data->size_b);
		extr->min_2 = find_second_min(data->stack_b, data->size_b);
		extr->max = find_max(data->stack_b, data->size_b);
		extr->max_2 = find_second_max(data->stack_b, data->size_b);
	}
}

void	sort_stack_a(t_data *data, int size)
{
	int	i;

	i = -1;
	free(data->sorted);
	data->sorted = malloc(sizeof(int) * data->size_a);
	if (!data->sorted)
		exit(EXIT_FAILURE);
	while (++i < data->size_a)
		data->sorted[i] = data->stack_a[i];
	ft_sort_int_tab(data->sorted, size);
}

void	sort_stack_b(t_data *data)
{
	int	i;

	i = -1;
	free(data->sorted);
	data->sorted = malloc(sizeof(int) * data->size_b);
	if (!data->sorted)
		exit(EXIT_FAILURE);
	while (++i < data->size_b)
		data->sorted[i] = data->stack_b[i];
	ft_sort_int_tab(data->sorted, data->size_b);
}

void	alg_push_a(t_data *data)
{
	push_a(data);
	if (data->size_index == 0)
		new_sizes_pos(data);
}

void	alg_push_rotate_a(t_data *data)
{
	push_a(data);
	rotate_a(data);
	data->ordered++;
}
