#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max);

int main()
{
	int **s1 = malloc(sizeof(int*) * 1);
	int min = -1;
	int max = 3;
	//s1[0] = malloc(sizeof(int) * (max - min));

	//ft_ultimate_range(s1, min, max);
	//printf("%p\n", s1[0]);

	printf("%d\n", ft_ultimate_range(s1, min, max));
	int i = 0;
	while(i < (max - min))
	{
		printf("%d\n", s1[0][i]);
		i++;
	}
}
