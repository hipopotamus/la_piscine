#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);

int main()
{
	int j = 4;
	int set[4] = {4,3,1,6};
	int i = 0;

	ft_sort_int_tab(set,j);
	while(i< j)
	{
		printf("%d", set[i]);
		i++;
	}
}
