#include <stdio.h>

int *ft_range(int min, int max);

int main()
{
	int i = 0;
	int min = 0;
	int max = 0;
	while(i < max - min)
	{
		printf("%d\n", ft_range(min, max)[i]);
		i++;
	}
	//printf("%p",ft_range(3,2));
}
