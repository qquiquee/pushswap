#include "../../include/push_swap.h"

void	reverse_rotate_a(t_data *data)
{
	reverse_rotate(data->stack_a, data->size_a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	reverse_rotate_b(t_data *data)
{
	reverse_rotate(data->stack_b, data->size_b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	reverse_rotate_a_b(t_data *data)
{
	reverse_rotate(data->stack_a, data->size_a);
	reverse_rotate(data->stack_b, data->size_b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}

void	swap_a(t_data *data)
{
	swap(data->stack_a, data->size_a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	swap_b(t_data *data)
{
	swap(data->stack_b, data->size_b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}
