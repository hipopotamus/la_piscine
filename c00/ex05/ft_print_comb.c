/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:30:15 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/20 19:39:19 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_n(int num)
{
	char	one;
	char	ten;
	char	hund;
	int		input_num;

	input_num = num;
	one = num % 10 + '0';
	num = num / 10;
	ten = num % 10 + '0';
	num = num / 10;
	hund = num % 10 + '0';
	if (hund < ten && ten < one)
	{
		write(1, &hund, 1);
		write(1, &ten, 1);
		write(1, &one, 1);
		if (input_num != 789)
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	int num;

	num = 0;
	while (num <= 789)
	{
		print_n(num);
		num++;
	}
}
