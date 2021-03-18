/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:05:25 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/17 20:45:17 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		except(char *str)
{
	int i;
	int j;

	if (str_len(str) == 0 || str_len(str) == 1)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	convert(long n, char *str)
{
	int size;

	size = str_len(str);
	if (n <= 0)
		return ;
	convert(n / size, str);
	write(1, &str[n % size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long nbr_long;

	if (except(base) == 0)
		return ;
	nbr_long = nbr;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (nbr < 0)
	{
		nbr_long = -nbr_long;
		write(1, "-", 1);
	}
	convert(nbr_long, base);
}
