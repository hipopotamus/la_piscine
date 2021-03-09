#include <unistd.h>
#include <stdlib.h>

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
	return(arr);
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

void	put_arr(int **arr, char *input, int n)
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

int		check_input(char* input, int n)
{
	int i;

	i = 0;
	while (input[i] != '\0')
	{
		if (i % 2 == 0) 
		{
			if (input[i] < '1' || ('0' + n) < input[i])
				return (0);
		}
		else if (input[i] != ' ')
				return (0);
		i++;
	}
	if (i != (2 * 4 * n ) - 1)
		return (0);
	return (1);	
}

void	print_error(void)
{
	write(1, "Error", 6);
	write(1, "\n", 1);
}
