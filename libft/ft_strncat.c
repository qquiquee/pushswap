#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	char			*temp;
	size_t			i;

	temp = dest;
	i = 0;
	while (*dest)
	{
		dest++;
	}
	while (*src && i < nb)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = '\0';
	dest = temp;
	return (dest);
}
