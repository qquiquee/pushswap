#include "../../include/push_swap.h"

void	swap(int *tab, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
}

static void	change_stack_b(int **tab_a, int **tab_b, int *size_b)
{
	int	*aux;
	int	i;

	i = 0;
	aux = *tab_b;
	*tab_b = malloc(sizeof(int) * *size_b);
	if (!*tab_b)
		exit(EXIT_FAILURE);
	(*tab_b)[0] = (*tab_a)[0];
	while (++i < *size_b)
		(*tab_b)[i] = aux[i - 1];
	if (aux)
		free(aux);
}

static void	change_stack_a(int **tab_a, int *size_a)
{
	int	*aux;
	int	i;

	aux = *tab_a;
	if (*size_a == 0)
		*tab_a = NULL;
	else
	{
		*tab_a = malloc(sizeof(int) * (*size_a));
		if (!*tab_a)
			exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < *size_a)
		(*tab_a)[i] = aux[i + 1];
	free(aux);
}

void	push(int **tab_a, int **tab_b, int *size_a, int *size_b)
{
	if (*size_a == 0)
		return ;
	*size_b += 1;
	*size_a -= 1;
	change_stack_b(tab_a, tab_b, size_b);
	change_stack_a(tab_a, size_a);
}
