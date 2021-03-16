/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_checkblank.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:12:54 by jiskim            #+#    #+#             */
/*   Updated: 2021/03/07 23:01:45 by byu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01_header.h"

void	put_edge(int **edge, int input, int row, int col)
{
	edge[row][col] = input;
}

int		is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int		check_input(int **edge, char *input)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (input[i] != '\0')
	{
		while (input[i] && is_space(input[i]))
			i++;
		if (input[i])
		{
			if ('1' <= input[i] && input[i] <= g_n + '0')
			{
				if (cnt == g_n * 4 || (input[i + 1] && !is_space(input[i + 1])))
					return (0);
				put_edge(edge, input[i] - '0', cnt / 4, cnt % 4);
				cnt++;
			}
			else
				return (0);
			++i;
		}
	}
	return (cnt == g_n * 4);
}
