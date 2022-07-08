#include "../../include/checker.h"

static void	check_args_2(int argc, char **argv, t_data *data)
{
	int		i;
	int		j;

	(void)argv;
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (data->args[i] == data->args[j])
				ft_error(data);
			j++;
		}
		i++;
	}
}

static void	convert_stack_a(int argc, char **argv, t_data *data)
{
	t_list	*node;
	int		i;
	long	temp;

	i = 1;
	data->args = malloc(sizeof(int) * (argc - 1));
	if (!data->args)
		exit(EXIT_FAILURE);
	while (i < argc)
	{
		temp = ft_atol(argv[i]);
		if (temp < -2147483648 || temp > 2147483647)
			ft_error(data);
		data->args[i - 1] = (int)temp;
		node = ft_lstnew(&data->args[i - 1]);
		ft_lstadd_back(&data->stack_a, node);
		i++;
	}
	check_args_2(argc, argv, data);
}

static void	check_args(int argc, char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
		ft_error(data);
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
		i++;
	}
	convert_stack_a(argc, argv, data);
}

static void	init_data(int argc, t_data *data)
{
	data->args = NULL;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->line = NULL;
	data->size = argc - 1;
	data->op_num = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(argc, &data);
	check_args(argc, argv, &data);
	while (get_next_line(STDIN_FILENO, &data.line) > 0)
		execute_command(&data);
	check_order(data);
	printf("Número total de movimientos = %d\n", data.op_num);
	free_all(&data);
	return (0);
}
