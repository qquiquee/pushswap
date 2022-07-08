int	ft_isalpha(int i)
{
	if (i >= 'A' && i <= 'Z')
		return (1);
	else if (i >= 'a' && i <= 'z')
		return (2);
	else
		return (0);
}
