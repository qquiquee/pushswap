#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_el
{
	int		pos;
	int		val;
}	t_el;

typedef struct s_data
{
	int		*stack_a;
	int		*stack_b;
	int		*a_sorted;
	int		*sorted;
	int		*sizes;
	int		compare;
	int		ordered;
	int		orig_size;
	int		size_a;
	int		size_b;
	int		index;
	int		rot_num;
	int		op_num;
	int		new_size;
	int		size_of_sizes;
	int		size_index;
	t_el	pivot;
}	t_data;

typedef struct s_extr
{
	t_el	min;
	t_el	min_2;
	t_el	max;
	t_el	max_2;
}	t_extr;

enum	e_bool
{
	FALSE,
	TRUE
};

void	print_int_tab(int *tab, int size);
void	ft_error(t_data *data);
long	ft_atol(const char *str);
void	print_stacks(t_data data);
void	free_all(t_data *data);

void	swap(int *tab, int size);
void	push(int **tab_a, int **tab_b, int *size_a, int *size_b);
void	rotate(int *tab, int size);
void	reverse_rotate(int *tab, int size);

void	push_b(t_data *data);
void	push_a(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_a_b(t_data *data);

void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	reverse_rotate_a_b(t_data *data);
void	swap_a(t_data *data);
void	swap_b(t_data *data);

int		check_order(int *tab, int size);
int		check_reverse_order(int *tab, int size);
int		check_left_a(int *stack, int size, t_el pivot);
int		check_left_b(int *stack, int size, t_el pivot);

t_el	find_min(int *tab, int size);
t_el	find_second_min(int *tab, int size);
t_el	find_max(int *tab, int size);
t_el	find_second_max(int *tab, int size);

void	own_algorithm(t_data *data);
void	push_swap(t_data *data);

void	rot_and_push_b(t_data *data, int size);
void	mod_QS_alg_a(t_data *data, int size);
void	mod_QS_alg_b(t_data *data);
void	return_from_b(t_data *data);
int		push_ordered_back(t_data *data);

void	init_extr(t_data *data, t_extr *extr, int stack);
void	sort_stack_a(t_data *data, int size);
void	sort_stack_b(t_data *data);
void	alg_push_a(t_data *data);
void	alg_push_rotate_a(t_data *data);

int		find_size(t_data *data, int val);
void	reduce_size_pos(t_data *data);

void	new_sizes_pos(t_data *data);
void	rot_and_push_b(t_data *data, int size);
void	return_from_b(t_data *data);

#endif
