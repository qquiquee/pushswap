#include "../../include/push_swap.h"

static void	own_algorithm_5(t_data *data)
{
	t_extr	extr;

	while (!(check_order(data->stack_a, data->size_a) == TRUE
			&& data->size_a == data->orig_size))
	{
		while (check_order(data->stack_a, data->size_a) == FALSE)
		{
			init_extr(data, &extr, 1);
			if (extr.min.pos == 0)
				push_b(data);
			else if (extr.min.pos == 1 && extr.min_2.pos == 0)
				swap_a(data);
			else if (extr.min.pos > data->size_a / 2)
				reverse_rotate_a(data);
			else if (extr.min.pos <= data->size_a / 2)
				rotate_a(data);
		}
		while (data->size_a != data->orig_size)
			push_a(data);
	}
}

static void	own_algorithm_3(t_data *data)
{
	t_extr	extr;

	while (check_order(data->stack_a, data->size_a) == FALSE)
	{
		init_extr(data, &extr, 1);
		if (extr.min_2.pos == 0 && extr.min.pos == 2)
			reverse_rotate_a(data);
		else if (extr.min_2.pos == 2 && extr.min.pos == 1)
			rotate_a(data);
		else
			swap_a(data);
	}
}

void	own_algorithm(t_data *data)
{
	if (data->size_b > 24)
		mod_QS_alg_b(data);
	else
	{
		return_from_b(data);
		push_ordered_back(data);
	}
	if (data->sizes)
	{
		data->new_size = (find_size(data, *(data->sizes)));
		reduce_size_pos(data);
	}
	else
	{
		data->new_size = (find_min(data->stack_a, data->size_a)).pos;
	}
	if (data->new_size < data->compare
		&& check_order(data->stack_a, data->size_a) == FALSE)
	{
		rot_and_push_b(data, data->new_size);
		return_from_b(data);
		push_ordered_back(data);
	}
	else if (check_order(data->stack_a, data->size_a) == FALSE)
		mod_QS_alg_a(data, data->new_size);
}

void	push_swap(t_data *data)
{
	if (check_order(data->stack_a, data->size_a) == FALSE)
	{
		if (data->size_a < 4)
			own_algorithm_3(data);
		else if (data->size_a < 6)
			own_algorithm_5(data);
		else
			mod_QS_alg_a(data, data->size_a);
	}
}
