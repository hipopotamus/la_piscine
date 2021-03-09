#include <stdio.h>

int *ft_range(int min, int max);

int main()
{
	int i = 0;
	while(i < 3)
	{
		printf("%d\n", ft_range(3,2));
		i++;
	}
}
