#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n && *str1 == *str2)
	{
		i++;
		str1++;
		str2++;
	}
	if (i == n)
		return (0);
	return (*str1 - *str2);
}
