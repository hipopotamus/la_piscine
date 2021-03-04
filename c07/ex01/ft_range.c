#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int size;
	int *range;

	if (min >= max)
		return (0);
	size = (max - min);
	range = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
