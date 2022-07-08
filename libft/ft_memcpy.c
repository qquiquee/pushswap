#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*srcc;
	char	*destc;
	int		i;

	i = 0;
	destc = (char *)dest;
	srcc = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (n > 0)
	{
		destc[i] = srcc[i];
		i++;
		n--;
	}
	return (dest);
}
