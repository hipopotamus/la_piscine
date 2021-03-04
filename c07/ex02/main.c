#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max);

int main()
{
	int **s1 = malloc(sizeof(int*) * 1);
	s1[0] = malloc(sizeof(int) * 4);

	printf("%d\n", ft_ultimate_range(s1, -1, 3));
	int i = 0;
	while(i < 4)
	{
		printf("%d\n", s1[0][i]);
		i++;
	}
}
