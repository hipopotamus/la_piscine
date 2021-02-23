#include <stdio.h>

void ft_rev_int_tab(int *tab, int size);

int main()
{
	int set[5] = {1, 2, 3, 4, 5};
	int size = 5;
	int i = 0;

	ft_rev_int_tab(set, size);
	while(i<5)
	{
		printf("%d", set[i]);
		i++;
	}
}
