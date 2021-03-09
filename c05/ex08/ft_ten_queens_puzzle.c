/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:24:52 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/09 18:39:48 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_res(int *position)
{
	int i;
	int temp;

	i = 0;
	while (i < 10)
	{
		temp = position[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int		check_position(int *c, int row)
{
	int i;

	i = 0;
	while (i < row)
	{
		if (c[row] == c[i] || ft_abs(c[row] - c[i]) == ft_abs(row - i))
			return (0);
		i++;
	}
	return (1);
}

int		check_brunch(int *position, int row)
{
	int col;

	col = 0;
	while (col < 10)
	{
		position[row] = col;
		if (check_position(position, row) == 1)
		{
			if (row == 9)
				print_res(position);
			if (row < 9)
				check_brunch(position, row + 1);
		}
		col++;
	}
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	int position[10];
	int row;

	row = 0;
	return (check_brunch(position, row));
}
