int ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] < 'a' || 'z' < str[i])
			return (0);
	}
	return (1);
}
