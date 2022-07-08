#include "libft.h"

size_t	ft_strarrlen(char **info)
{
	size_t	i;

	i = 0;
	while (info[i])
		i++;
	return (i);
}
