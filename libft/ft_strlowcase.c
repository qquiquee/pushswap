char	*ft_strlowcase(char *str)
{
	char	*temp;

	temp = str;
	while (*str)
	{
		if (*str >= 65 && *str <= 90)
			*str = *str + 32;
		str++;
	}
	str = temp;
	return (str);
}
