#include "../../include/push_swap.h"

int	check_order(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_reverse_order(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] < tab[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_left_a(int *stack, int size, t_el pivot)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] < pivot.val)
			return (1);
		i++;
	}
	return (0);
}

int	check_left_b(int *stack, int size, t_el pivot)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] > pivot.val)
			return (1);
		i++;
	}
	return (0);
}
