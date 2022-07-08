#include "../../include/push_swap.h"

void	push_b(t_data *data)
{
	push(&data->stack_a, &data->stack_b, &data->size_a, &data->size_b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

void	push_a(t_data *data)
{
	push(&data->stack_b, &data->stack_a, &data->size_b, &data->size_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	rotate_a(t_data *data)
{
	rotate(data->stack_a, data->size_a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rotate_b(t_data *data)
{
	rotate(data->stack_b, data->size_b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rotate_a_b(t_data *data)
{
	rotate(data->stack_a, data->size_a);
	rotate(data->stack_b, data->size_b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
