#include "rush01_header.h"

int		g_n;
int		flag;

int main(int argc, char** argv)
{
	int **map;
	int **input;

	g_n = 4;
	if (argc != 2)
	{
		print_error();
		return (0);
	}
	if (check_input(argv[1], g_n) == 0)
	{
		print_error();
		return (0);
	}
	input = make_arr(4, g_n);
	put_arr(input, argv[1], g_n);
	map = make_arr(g_n, g_n);
	init_map(map, g_n);
	put_nbox(1, 0, map, input);
	if (flag == 0)
		print_error();
}
