#include "../../include/push_swap.h"

void	new_sizes_pos(t_data *data)
{
	int	*aux;
	int	i;

	i = 0;
	data->size_of_sizes++;
	aux = data->sizes;
	data->sizes = malloc(sizeof(int) * data->size_of_sizes);
	if (!data->sizes)
		exit(EXIT_FAILURE);
	(data->sizes)[0] = (data->stack_a)[0];
	while (++i < data->size_of_sizes)
		(data->sizes)[i] = aux[i - 1];
	if (aux)
		free(aux);
	data->size_index = 1;
}

void	rot_and_push_b(t_data *data, int size)
{
	while (size > 0)
	{
		if (data->stack_a[0] == data->stack_a[data->size_a - 1] + 1)
		{
			rotate_a(data);
			data->ordered++;
		}
		else
			push_b(data);
		size--;
	}
}

static void	push_and_swap_a(t_data *data)
{
	push_a(data);
	swap_a(data);
	data->index = 0;
}

static void	push_and_rotate_a(t_data *data)
{
	push_a(data);
	rotate_a(data);
	data->ordered++;
}

void	return_from_b(t_data *data)
{
	t_extr	extr;

	while (data->size_b)
	{
		init_extr(data, &extr, 2);
		if (extr.max.pos == 0 && data->index == 0)
			push_a(data);
		else if (extr.max.pos == 0 && data->index == 1)
			push_and_swap_a(data);
		else if (extr.min.pos == 0)
			push_and_rotate_a(data);
		else if (extr.max_2.pos == 0 && data->index == 0)
		{
			push_a(data);
			data->index = 1;
		}
		else if (extr.max.pos > data->size_a / 2)
			reverse_rotate_b(data);
		else if (extr.max.pos <= data->size_a / 2)
			rotate_b(data);
	}
}
