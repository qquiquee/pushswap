#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*f_str;
	unsigned int	i;
	int				len;

	if (s && f)
	{
		i = 0;
		len = ft_strlen((char *)s);
		f_str = (char *)malloc(len + 1);
		if (!f_str)
			return (NULL);
		while (s[i] != 0)
		{
			f_str[i] = f(i, s[i]);
			i++;
		}
		f_str[i] = 0;
		return (f_str);
	}
	return (NULL);
}
