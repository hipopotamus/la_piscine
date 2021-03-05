#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str *ft_strs_to_tab(int ac, char **av);

int main()
{
	t_stock_str *s1;
	char **s2 = malloc(sizeof(char*) * 3);
	s2[0] = "hellow";
	s2[1] = "hi";
	s2[2] = "hey";
	s1 = ft_strs_to_tab(3, s2);
	printf("%d\n", s1[2].size);
}
