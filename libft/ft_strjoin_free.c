#include "libft.h"

/*
** Join s1 and s2 and return the new string
** Free the strings based on a flag
*/

char	*ft_strjoin_free(char *s1, char *s2, size_t flag)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (flag == FREE_FIRST)
		free(s1);
	else if (flag == FREE_SECOND)
		free(s2);
	else if (flag == FREE_BOTH)
	{
		free(s1);
		free(s2);
	}
	return (ret);
}
