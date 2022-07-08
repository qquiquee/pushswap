#include "../../include/push_swap.h"

static void	check_args_2(int argc, t_data *data)
{
	int		i;
	int		j;

	if (argc == 1)
		ft_error(data);
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (data->stack_a[i] == data->stack_a[j])
				ft_error(data);
			j++;
		}
		i++;
	}
	data->size_a = argc - 1;
	data->orig_size = argc - 1;
}

static void	check_args(int argc, char **argv, t_data *data)
{
	int		i;
	int		j;
	long	temp;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				ft_error(data);
			j++;
		}
		temp = ft_atol(argv[i]);
		if (temp < -2147483648 || temp > 2147483647)
			ft_error(data);
		data->stack_a[i - 1] = (int)temp;
		data->a_sorted[i - 1] = (int)temp;
		i++;
	}
	check_args_2(argc, data);
}

static void	init_data(int argc, t_data *data)
{
	data->stack_a = malloc(sizeof(int) * (argc - 1));
	data->stack_b = NULL;
	data->size_b = 0;
	data->a_sorted = malloc(sizeof(int) * (argc - 1));
	data->sorted = malloc(sizeof(int) * (argc - 1));
	data->ordered = 0;
	data->index = 0;
	data->rot_num = 0;
	data->op_num = 0;
	data->new_size = 0;
	data->sizes = NULL;
	data->size_of_sizes = 0;
	data->size_index = 0;
	if (argc > 250)
		data->compare = 75;
	else
		data->compare = 35;
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(argc, &data);
	check_args(argc, argv, &data);
	ft_sort_int_tab(data.a_sorted, argc - 1);
	push_swap(&data);
	free_all(&data);
}
