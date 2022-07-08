#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	cont;
	unsigned int	i;

	cont = 0;
	if (src == NULL)
		return (0);
	while (src[cont])
	{
		cont++;
	}
	i = 0;
	if (size == 0)
		return (cont);
	else
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (cont);
}
