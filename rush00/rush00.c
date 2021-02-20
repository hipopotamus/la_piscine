/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa </var/mail/sungwopa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:52:09 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/20 21:43:41 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c);

void		print_row(char *str_set, int col)
{
	int	i;

	i = 1;
	while (i <= col)
	{
		if (i == 1)
			ft_putchar(str_set[0]);
		else if (i < col)
			ft_putchar(str_set[1]);
		else if (i == col)
			ft_putchar(str_set[2]);
		i++;
	}
	write(1, "\n", 1);
}

void		rush(int col, int row)
{
	char	*start;
	char	*mid;
	char	*end;
	int		j;

	start = "o-o";
	mid = "| |";
	end = "o-o";
	if (row <= 0 || col <= 0)
		return ;
	j = 1;
	while (j <= row)
	{
		if (j == 1)
			print_row(start, col);
		else if (j < row)
			print_row(mid, col);
		else if (j == row)
			print_row(end, col);
		j++;
	}
}
