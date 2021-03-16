/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:57:22 by byu               #+#    #+#             */
/*   Updated: 2021/03/07 17:21:26 by byu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01_header.h"

void	free_map(int **map)
{
	int		index;

	index = 0;
	while (index < g_n)
	{
		free(map[index]);
		index++;
	}
	free(map);
}

void	free_input(int **input)
{
	int		index;

	index = 0;
	while (index < 4)
	{
		free(input[index]);
		index++;
	}
	free(input);
}
