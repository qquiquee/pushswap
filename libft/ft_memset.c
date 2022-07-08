#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*temp;

	temp = (char *)s;
	if (n)
	{
		while (n > 0)
		{
			*temp = c;
			temp++;
			n--;
		}
	}
	return (s);
}
