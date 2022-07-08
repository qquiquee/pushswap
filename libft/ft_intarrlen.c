#include "libft.h"

size_t	ft_intarrlen(int *tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}
