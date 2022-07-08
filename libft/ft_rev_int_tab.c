#include "libft.h"

void	ft_rev_int_tab(int *tab, int size)
{
	int	*revtab;
	int	i;

	revtab = (int *)malloc(sizeof(int) * size);
	if (!revtab)
		return ;
	i = 0;
	while (i < size)
	{
		revtab[i] = *(tab + size - 1 - i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		*(tab + i) = revtab[i];
		i++;
	}
}
