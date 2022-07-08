#include "libft.h"

static int	ft_checkset(char c, const char *set)
{
	int		i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_start(int *start, int *len, char const *s1, const char *set)
{
	while (s1[*len] != 0)
	{
		if (ft_checkset(s1[*len], set) == 0)
		{
			*start = *len;
			break ;
		}
		*len += 1;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	int		slen;

	if (!s1)
		return (NULL);
	start = 0;
	len = 0;
	slen = ft_strlen((char *)s1) + 1;
	ft_start(&start, &len, s1, set);
	len = 0;
	while (--slen > 0)
	{
		if (ft_checkset(s1[slen - 1], set) == 0)
		{
			len = slen - start;
			break ;
		}
	}
	return (ft_substr(s1, start, len));
}
