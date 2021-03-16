/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:42:19 by byu               #+#    #+#             */
/*   Updated: 2021/03/07 22:55:25 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_HEADER_H
# define RUSH01_HEADER_H
# include <unistd.h>
# include <stdlib.h>

extern	int	g_n;
extern	int	g_flag;
int		c_row(int **map, int is_left, int row_idx, int row_check);
int		c_columb(int **map, int is_upper, int columb_idx, int columb_value);
int		finalcheck(int **map, int **edge_num);
void	print_arr(int **map, int ncol, int nrow);
int		is_valid_position(int **map, int columb, int inserting_value);
int		is_possible(int value, int col, int row, int **map);
void	put_nbox(int num, int row, int **map, int **input);
void	init_map(int **map, int n);
void	print_error(void);
void	put_arr(int **arr, char *input, int n);
int		**make_arr(int nrow, int ncol);
void	free_map(int **map);
void	free_input(int **input);
void	put_edge(int **edge, int input, int row, int col);
int		is_space(char c);
int		check_input(int **edge, char *input);
#endif
