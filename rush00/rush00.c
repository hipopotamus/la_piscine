/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa </var/mail/sungwopa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:20:48 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/20 13:53:47 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_row(char *str_set, int row)
{
	int i;
	i = 1;

	while (i <= row)
	{
		if (i == 1)
			ft_putchar(str_set[0]);
		else if (i < row)
			ft_putchar(str_set[1]);
		else if (i == row)
			ft_putchar(str_set[2]);
		i++;
	}
	write(1, "\n", 1);
}

void	rush(int row, int col)
{
	char *start_end = "o-o";
	char *mid = "| |";

	if (row == 0 || col == 0)
	{
		return ;
	}

	int j;
	j = 1;

	while(j <= col)
	{
		if (j == 1)
			print_row(start_end, row);
		else if (j < col)
			print_row(mid, row);
		else if (j == col)
			print_row(start_end, row);
		j++;
	}
}


