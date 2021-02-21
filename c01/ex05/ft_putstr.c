int str_len(char *str)
{
	int i;

	i = 0;
	while(str[i] < '\0')
		i++;
	return(i+1);
}

void ft_putstr(char *str)
{
	int len;
	int i;

	len = str_len(str);
	i = -1;
	while(++i < str_len)
	{
		write(1, &str[i], 1);
	}
}
