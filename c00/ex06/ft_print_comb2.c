/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:55:31 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/20 20:45:52 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_range(int end_n)
{
	char start;
	char end;

	start = '0';
	end = '0';
	range_end = '0' + end_n;

	while(start <= '9')
	{
		while(end <= range_end)
		{
			write(1, &start, 1);
			write(1, &end, 1);
		}
		start++;
		end = '0';
	}
}


void ft_print_comb2(void)
{
	int col;
	int row;

	col = 0;
	row = 0;

	while(col < 9)
	{
		if (
		ft_print_range(9);
		while(row < 9)
		{
			ft_print_range(9)
		}
	}


}
