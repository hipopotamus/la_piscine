/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:55:31 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/20 21:36:20 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int power(int a, int b)
{
	int i;
	int temp = a;

	i = 1;
	while(i < b)
	{
		a = a*temp;
		i++;
	}
	return(a);
}

void convert(int n, int s)
{
	char buff[s];
	int i;
	int j;

	j = power(10,s-1);
	i = 0;
	while (i <= s-1)
	{
		if ((n / j) < 1)
			buff[i] = '0';
		else
			buff[i] = '0' + (n / j);
		n = n%j;
		i++;
		j = j/10;
	}
	write(1, buff, s);
}

void  ft_print_comb2()
{
	int i;
	int j;
	char *set;

	i = 0;
	set = " , ";

	while(i <= 98)
	{
		j = i+1;
		while (i < j && j <= 99)
		{
			convert(i,2);
			write(1, &set[0], 1);
			convert(j,2);
			if (i < 98)
				write(1, &set[1], 2);
			j++;
		}
		i++;
	}
}
