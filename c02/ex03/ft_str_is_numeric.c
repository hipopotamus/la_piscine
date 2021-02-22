int ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] < '0' || '9' < str[i])
			return (0);
	}
	return (1);
}
