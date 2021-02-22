int ft_str_is_uppercase(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] < 'A' || 'Z' < str[i])
			return (0);
	}
	return (1);
}
