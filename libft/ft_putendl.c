#include "libft.h"

void	ft_putendl(char *str)
{
	if (!str)
		return ;
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}
