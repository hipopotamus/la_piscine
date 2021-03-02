int	check_prime(int nb)
{
	int i;
	
	if (nb < 2)
		return (0);
	i = 2;
	while(i * i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (1)
	{
		if (check_prime(nb) == 1)
			return (nb);
		nb++;
	}
}
