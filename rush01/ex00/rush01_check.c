/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:27:02 by jiskim            #+#    #+#             */
/*   Updated: 2021/03/07 16:43:19 by byu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01_header.h"

int		c_row(int **map, int is_left, int row_idx, int row_check)
{
	int		index;
	int		max;
	int		cnt;

	index = 0;
	max = 0;
	cnt = 0;
	while (index < g_n)
	{
		if (map[row_idx][index] > max && is_left)
		{
			cnt++;
			max = map[row_idx][index];
		}
		if (map[row_idx][g_n - 1 - index] > max && !is_left)
		{
			cnt++;
			max = map[row_idx][g_n - 1 - index];
		}
		index++;
	}
	return (cnt == row_check ? 1 : 0);
}

int		c_columb(int **map, int is_upper, int columb_idx, int columb_value)
{
	int		index;
	int		max;
	int		cnt;

	index = 0;
	max = 0;
	cnt = 0;
	while (index < g_n)
	{
		if (map[index][columb_idx] > max && is_upper)
		{
			cnt++;
			max = map[index][columb_idx];
		}
		if (map[g_n - 1 - index][columb_idx] > max && !is_upper)
		{
			cnt++;
			max = map[g_n - 1 - index][columb_idx];
		}
		index++;
	}
	return (cnt == columb_value ? 1 : 0);
}

int		finalcheck(int **map, int **edge_num)
{
	int		row;
	int		columb;

	row = -1;
	while (++row < 4)
	{
		columb = -1;
		while (++columb < g_n)
		{
			if (row == 0 && !c_columb(map, 1, columb, edge_num[row][columb]))
				return (0);
			if (row == 1 && !c_columb(map, 0, columb, edge_num[row][columb]))
				return (0);
			if (row == 2 && !c_row(map, 1, columb, edge_num[row][columb]))
				return (0);
			if (row == 3 && !c_row(map, 0, columb, edge_num[row][columb]))
				return (0);
		}
	}
	return (1);
}
