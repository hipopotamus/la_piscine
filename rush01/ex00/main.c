/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:34:10 by byu               #+#    #+#             */
/*   Updated: 2021/03/07 22:53:49 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01_header.h"

int		g_n;
int		g_flag;

int		main(int argc, char **argv)
{
	int		**map;
	int		**input;

	g_n = 4;
	if (argc != 2)
	{
		print_error();
		return (0);
	}
	input = make_arr(4, g_n);
	if (check_input(input, argv[1]) == 0)
	{
		print_error();
		return (0);
	}
	map = make_arr(g_n, g_n);
	init_map(map, g_n);
	put_nbox(1, 0, map, input);
	if (g_flag == 0)
		print_error();
	free_map(map);
	free_input(input);
	return (0);
}
