#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct s_data
{
	int		*args;
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;
	int		size;
	int		op_num;
}	t_data;

int		swap(t_list **list);
int		push(t_list **list_a, t_list **list_b);
int		rotate(t_list **list);
int		reverse_rotate(t_list **list);

void	del_first_node(t_list **list);
void	del_last_node(t_list **list);
void	free_list(t_list **list);
void	free_all(t_data *data);
void	check_order(t_data data);

void	print_content(void *content);
void	print_stacks(t_list *list1, t_list *list2);
void	ft_error(t_data *data);
long	ft_atol(const char *str);

void	execute_command(t_data *data);
void	execute_command_2(t_data *data);

#endif
