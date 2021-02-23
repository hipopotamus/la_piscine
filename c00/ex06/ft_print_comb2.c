/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:55:31 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/23 21:12:55 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		power(int a, int b)
{
	int i;
	int temp;

	temp = a;
	i = 1;
	while (i < b)
	{
		a = a * temp;
		i++;
	}
	return (a);
}

void	convert(int n, int size)
{
	char	buff[size];
	int		i;
	int		j;

	j = power(10, size - 1);
	i = 0;
	while (i <= size - 1)
	{
		if ((n / j) < 1)
			buff[i] = '0';
		else
			buff[i] = '0' + (n / j);
		n = n % j;
		j = j / 10;
		i++;
	}
	write(1, buff, size);
}

void	ft_print_comb2(void)
{
	int		first;
	int		sec;
	char	*set;

	first = 0;
	set = ", ";
	while (first <= 98)
	{
		sec = first + 1;
		while (sec <= 99)
		{
			convert(first, 2);
			write(1, &set[1], 1);
			convert(sec, 2);
			if (first < 98)
				write(1, set, 2);
			sec++;
		}
		first++;
	}
}
