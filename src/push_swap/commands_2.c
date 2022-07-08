#include "../../include/push_swap.h"

void	rotate(int *tab, int size)
{
	int	aux;
	int	i;

	i = -1;
	if (size < 2)
		return ;
	aux = tab[0];
	while (++i < size - 1)
		tab[i] = tab[i + 1];
	tab[i] = aux;
}

void	reverse_rotate(int *tab, int size)
{
	int	aux;

	if (size < 2)
		return ;
	aux = tab[size - 1];
	while (--size)
		tab[size] = tab[size - 1];
	tab[0] = aux;
}
