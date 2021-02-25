#include <stdio.h>
#include <string.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int main()
{
	char s1[80];

	printf("%d\n", ft_strlcpy(s1, "123456789", 3));
	printf("%s\n", s1); 
}
