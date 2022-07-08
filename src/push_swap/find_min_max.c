#include "../../include/push_swap.h"

t_el	find_min(int *tab, int size)
{
	int		i;
	t_el	el;

	i = 1;
	el.pos = -1;
	el.val = 0;
	if (size < 1)
		return (el);
	el.pos++;
	while (i < size)
	{
		if (tab[el.pos] > tab[i])
		{
			el.pos = i;
			el.val = tab[i];
		}
		i++;
	}
	return (el);
}

t_el	find_second_min(int *tab, int size)
{
	t_el	min;
	t_el	min_2;
	int		i;

	min_2.pos = -1;
	min_2.val = 0;
	if (size < 2)
		return (min_2);
	i = 1;
	min_2.pos++;
	min = find_min(tab, size);
	if (min.pos == 0)
		min_2.pos = 1;
	while (i < size)
	{
		if (tab[min_2.pos] > tab[i] && i != min.pos)
		{
			min_2.pos = i;
			min_2.val = tab[i];
		}
		i++;
	}
	return (min_2);
}

t_el	find_max(int *tab, int size)
{
	int		i;
	t_el	el;

	i = 1;
	el.pos = -1;
	el.val = 0;
	if (size < 1)
		return (el);
	el.pos++;
	while (i < size)
	{
		if (tab[el.pos] < tab[i])
		{
			el.pos = i;
			el.val = tab[i];
		}
		i++;
	}
	return (el);
}

t_el	find_second_max(int *tab, int size)
{
	t_el	max;
	t_el	max_2;
	int		i;

	max_2.pos = -1;
	max_2.val = 0;
	if (size < 2)
		return (max_2);
	i = 1;
	max_2.pos++;
	max = find_max(tab, size);
	if (max.pos == 0)
		max_2.pos = 1;
	while (i < size)
	{
		if (tab[max_2.pos] < tab[i] && i != max.pos)
		{
			max_2.pos = i;
			max_2.val = tab[i];
		}
		i++;
	}
	return (max_2);
}
