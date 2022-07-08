#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*str;

	str = malloc(nelem * (elsize));
	if (!str)
		return (NULL);
	ft_memset(str, 0, nelem * (elsize));
	return (str);
}
