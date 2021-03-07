/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:56:34 by jiskim            #+#    #+#             */
/*   Updated: 2021/03/06 21:10:48 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int flag;
int g_n;

int		is_valid_row(int **map, int is_left, int row_idx, int row_check)
{
	int		index;
	int		max;
	int		cnt;

	index = 0;
	max = 0;
	cnt = 0;
	while (index < g_n && is_left)
	{
		if (map[row_idx][index] > max)
		{
			cnt++;
			max = map[row_idx][index];
		}
		index++;
	}
	while (index < g_n && !is_left)
	{
		if (map[row_idx][g_n - 1-index] > max)
		{
			cnt++;
			max = map[row_idx][g_n - 1 - index];
		}
		index++;
	}
	return (cnt == row_check ? 1 : 0);
}

int		is_valid_columb(int **map, int is_upper, int columb_idx, int columb_value)
{
	int		index;
	int		max;
	int		cnt;
	index = 0;
	max = 0;
	cnt = 0;
	while (index < g_n && is_upper)
	{
		if (map[index][columb_idx] > max)
		{
			cnt++;
			max = map[index][columb_idx];
		}
		index++;
	}	
	while (index < g_n && !is_upper)
	{
		if (map[g_n - 1 -index][columb_idx] > max)
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
	int		cnt;
	row = -1;
	cnt = 0;
	while (++row < 4)
	{
		columb = -1;
		while (++columb < g_n)
		{
			if (row == 0 && is_valid_columb(map, 1, columb, edge_num[row][columb]))
				cnt++;
			if (row == 1 && is_valid_columb(map, 0, columb, edge_num[row][columb]))
				cnt++;
			if (row == 2 && is_valid_row(map, 1, columb, edge_num[row][columb]))
				cnt++;
			if (row == 3 && is_valid_row(map, 0, columb, edge_num[row][columb]))
				cnt++;
		}
	}
	if (cnt == g_n * 4)
		return (1);
	else
		return (0);
}

void	print_arr(int **map, int ncol, int nrow)
{
	int row;
	int col;
	char c;

	row = 0;
	col = 0;
	while (row < nrow)
	{
		col = 0;
		while (col < ncol)
		{
			c = '0' + map[row][col];
			write(1, &c, 1);
			write(1, " ", 1);
			col++;
		}
		row++;
		write(1, "\n", 1);
	}
}

//세로로 테스트 한다.
int		is_valid_position(int **map, int columb, int inserting_value)
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

//가로로 테스트 + 세로로테스트가 ok뜨면 return
int		is_possible(int value, int col, int row, int** map)
{
	//is_valid_position은 현재 row의 위만 검사해도 될 것 같습니다.
	if (!map[row][col] && is_valid_position(map, col, value)) //0 -> return 1
		return (1);
	return (0);
}

/* 1부터 모든 row에 입력한 후 n까지 넣는다.
 * i 현재 넣는 수 n 최대값 row 현재 넣는 arr의 열
put_nbox(1, n, 0, map);으로 호출한다.
*/

void	put_nbox(int num, int row, int **map, int** input)
{
	int col;
	int cnt = 1;
	col = 0;

	if (num == g_n && row == g_n && finalcheck(map, input))//n까지 모든 열에 넣음
	{
		print_arr(map, g_n, g_n);
		flag = 1;
	}

	else if (num != g_n || row != g_n)
	{
		while (col < g_n)
		{
			if (is_possible(num, col, row, map))
			{
				map[row][col] = num;
				if (num < g_n && row == g_n - 1)
					put_nbox(num + 1, 0, map, input);//n을 다 채우면 row = 0으로 다시 시작
				else
					put_nbox(num, row + 1, map, input);
				map[row][col] = 0;
			}
			col++;
		}
	}
	return ;
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

void print_error(void)
{
	write(1, "Error", 6);
	write(1, "\n", 1);
}

void put_arr(int** arr, char* input, int n)
{
	int i;
	int j;
	int input_i;

	i = 0;
	input_i = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			arr[i][j] = (int)(input[input_i] - '0');
			j++;
			input_i = input_i + 2;
		}
		i++;
	}
}

int** make_edge(int n)
{
	int **arr;
	int i;

	i = 0;
	arr = (int**)malloc(sizeof(int*) * 4);
	while (i < n)
	{
		*(arr + i) = (int*)malloc(sizeof(int) * n);
		i++;
	}
	return(arr);
}

int** make_arr(int n)
{
	int **arr;
	int i;

	i = 0;
	arr = (int**)malloc(sizeof(int*) * n);
	while (i < n)
	{
		*(arr + i) = (int*)malloc(sizeof(int) * n);
		i++;
	}
	return(arr);
}
int check_input(char* input, int n)
{
	int i;

	i = 0;
	while(input[i] != '\0')
	{
		if (i % 2 == 0) 
		{
			if (input[i] < '1' || ('0' + n) < input[i])
			{
				return (0);
			}
		}
		else if (input[i] != ' ')
		{
				return (0);
		}
		i++;
	}
	if (i != (2 * 4 * n ) - 1)
		return (0);
		
	return (1);
	
}

int main(int argc, char** argv)
{
	int **map;
	int **input;

	g_n = 9;
	if (argc != 2)
	{
		print_error();
		write(1,"she",3);
		return (0);
	}
	if (check_input(argv[1], g_n) == 0)
	{
		print_error();
		write(1,"he", 2);
		return (0);
	}
	input = make_edge(g_n);
	put_arr(input, argv[1], g_n);
	map = make_arr(g_n);
	init_map(map, g_n);
	print_arr(input, g_n, 4);
	put_nbox(1, 0, map, input);
	if(flag == 0)
	{
		print_error();
		write(1, "hellow", 6);
	}
}
