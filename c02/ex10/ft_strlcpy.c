#include <unistd.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;

	i = 0;
	while(src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	while(src[i] != '\0')
		i++;
	return(i);
}

int main()
{
	char dest[5];
	char src[3] = "hed";

	ft_strlcpy(dest, src, 5);

	write(1, dest ,3);
}
