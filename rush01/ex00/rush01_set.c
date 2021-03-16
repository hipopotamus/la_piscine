/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:28:41 by jiskim            #+#    #+#             */
/*   Updated: 2021/03/07 22:41:26 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01_header.h"

int		**make_arr(int nrow, int ncol)
{
	int **arr;
	int i;

	i = 0;
	arr = (int**)malloc(sizeof(int*) * nrow);
	while (i < nrow)
	{
		*(arr + i) = (int*)malloc(sizeof(int) * ncol);
		i++;
	}
	return (arr);
}

void	init_map(int **map, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
			map[i][j++] = 0;
		i++;
	}
}

void	print_error(void)
{
	write(1, "Error", 5);
	write(1, "\n", 1);
}
