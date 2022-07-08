#include "../../include/push_swap.h"

int	find_size(t_data *data, int val)
{
	int	i;

	i = 0;
	while (data->stack_a[i] != val)
		i++;
	return (i + 1);
}

void	reduce_size_pos(t_data *data)
{
	int	*aux;
	int	i;

	aux = data->sizes;
	data->size_of_sizes--;
	if (data->size_of_sizes == 0)
		data->sizes = NULL;
	else
	{
		data->sizes = malloc(sizeof(int) * data->size_of_sizes);
		if (!data->sizes)
			exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < data->size_of_sizes)
		(data->sizes)[i] = aux[i + 1];
	free(aux);
}
