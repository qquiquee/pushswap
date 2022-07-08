#include "../../include/push_swap.h"

static void	init_data_alg_b(t_data *data)
{
	data->size_index = 0;
	data->pivot.val = data->sorted[data->size_b / 2];
	data->pivot.pos = data->size_b / 2;
}

void	mod_QS_alg_b(t_data *data)
{
	int		size;
	int		i;
	t_extr	extr;

	i = -1;
	init_data_alg_b(data);
	size = data->size_b;
	sort_stack_b(data);
	while (++i < size && check_left_b(data->stack_b, data->size_b, data->pivot))
	{
		init_extr(data, &extr, 2);
		if (data->stack_b[0] > data->pivot.val)
			alg_push_a(data);
		else if (extr.min.pos == 0)
			alg_push_rotate_a(data);
		else
			rotate_b(data);
	}
	own_algorithm(data);
}

int	push_ordered_back(t_data *data)
{
	while (data->stack_a[0] == data->a_sorted[data->ordered]
		&& data->ordered < data->orig_size)
	{
		rotate_a(data);
		data->ordered++;
	}
	return (data->size_a - data->ordered);
}

static void	return_stack_a_pos(t_data *data)
{
	if (data->ordered < data->rot_num)
	{
		while (data->size_a - data->rot_num)
		{
			rotate_a(data);
			data->rot_num++;
		}
	}
	else
	{
		while (data->rot_num)
		{
			reverse_rotate_a(data);
			data->rot_num--;
		}
	}
}

void	mod_QS_alg_a(t_data *data, int size)
{
	int		i;

	i = 0;
	data->rot_num = 0;
	sort_stack_a(data, size);
	data->pivot.val = data->sorted[size / 2];
	data->pivot.pos = size / 2;
	while (data->size_b <= size / 2
		&& check_left_a(data->stack_a, size, data->pivot))
	{
		if (data->stack_a[0] <= data->pivot.val)
			push_b(data);
		else
		{
			rotate_a(data);
			if (size < data->orig_size)
				data->rot_num++;
		}
		i++;
	}
	return_stack_a_pos(data);
	own_algorithm(data);
}
