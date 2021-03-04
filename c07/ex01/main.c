#include <stdio.h>

int *ft_range(int min, int max);

int main()
{
	int i = 0;
	while(i < 3)
	{
		printf("%d\n", ft_range(-1,1)[i]);
		i++;
	}
}
