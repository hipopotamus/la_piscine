int ft_iterative_power(int nb, int power)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while(i < power)
	{
		res = res*nb;
		i++;
	}
	return (res);
}
