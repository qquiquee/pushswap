#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str != '\0')
	{
		write(fd, str, 1);
		str++;
	}
}
