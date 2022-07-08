#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *)s;
	if (n)
	{
		while (n > 0)
		{
			*temp = '\0';
			temp++;
			n--;
		}
	}
}
