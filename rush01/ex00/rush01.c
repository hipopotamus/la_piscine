/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:28:22 by jiskim            #+#    #+#             */
/*   Updated: 2021/03/07 23:02:49 by byu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01_header.h"

void		print_arr(int **map, int ncol, int nrow)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	col = 0;
	while (row < nrow)
	{
		col = 0;
		while (col < ncol)
		{
			c = '0' + map[row][col];
			write(1, &c, 1);
			if (col < ncol - 1)
				write(1, " ", 1);
			col++;
		}
		row++;
		write(1, "\n", 1);
	}
}

int			is_valid_position(int **map, int columb, int inserting_value)
{
	int		index;

	index = 0;
	while (index < g_n)
	{
		if (map[index][columb] == inserting_value)
			return (0);
		index++;
	}
	return (1);
}

int			is_possible(int value, int col, int row, int **map)
{
	if (!map[row][col] && is_valid_position(map, col, value))
		return (1);
	return (0);
}

void		put_nbox(int num, int row, int **map, int **input)
{
	int col;

	col = 0;
	if (num == g_n && row == g_n && finalcheck(map, input) && g_flag == 0)
	{
		print_arr(map, g_n, g_n);
		g_flag = 1;
	}
	else if (num != g_n || row != g_n)
	{
		while (col < g_n)
		{
			if (is_possible(num, col, row, map))
			{
				map[row][col] = num;
				if (num < g_n && row == g_n - 1)
					put_nbox(num + 1, 0, map, input);
				else
					put_nbox(num, row + 1, map, input);
				map[row][col] = 0;
			}
			col++;
		}
	}
	return ;
}
