#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*srcc;
	char	*destc;
	size_t	i;

	i = 0;
	destc = (char *)dest;
	srcc = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	if (dest > src)
	{
		while (i < n)
		{
			destc[n - i - 1] = srcc[n - i - 1];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
