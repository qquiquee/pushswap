#include "../../include/checker.h"

void	execute_command_2(t_data *data)
{
	if (ft_strcmp(data->line, "ra") == 0)
		data->op_num += rotate(&data->stack_a);
	else if (ft_strcmp(data->line, "rb") == 0)
		data->op_num += rotate(&data->stack_b);
	else if (ft_strcmp(data->line, "rr") == 0)
	{
		rotate(&data->stack_a);
		data->op_num += rotate(&data->stack_b);
	}
	else if (ft_strcmp(data->line, "rra") == 0)
		data->op_num += reverse_rotate(&data->stack_a);
	else if (ft_strcmp(data->line, "rrb") == 0)
		data->op_num += reverse_rotate(&data->stack_b);
	else if (ft_strcmp(data->line, "rrr") == 0)
	{
		reverse_rotate(&data->stack_a);
		data->op_num += reverse_rotate(&data->stack_b);
	}
	else
		ft_error(data);
}

void	execute_command(t_data *data)
{
	if (ft_strcmp(data->line, "sa") == 0)
		data->op_num += swap(&data->stack_a);
	else if (ft_strcmp(data->line, "sb") == 0)
		data->op_num += swap(&data->stack_b);
	else if (ft_strcmp(data->line, "ss") == 0 )
	{
		if (ft_lstsize(data->stack_a) > 1)
			data->op_num += swap(&data->stack_a);
		if (ft_lstsize(data->stack_b) > 1)
			data->op_num += swap(&data->stack_b);
	}
	else if (ft_strcmp(data->line, "pa") == 0)
		data->op_num += push(&data->stack_b, &data->stack_a);
	else if (ft_strcmp(data->line, "pb") == 0)
		data->op_num += push(&data->stack_a, &data->stack_b);
	else
		execute_command_2(data);
}
