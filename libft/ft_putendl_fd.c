#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str != '\0')
	{
		write(fd, str, 1);
		str++;
	}
	write(fd, "\n", 1);
}
