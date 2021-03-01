#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int np);

int main()
{
	char s1[80] = "hellow";
	char s2[7] = "abcdef";

	printf("%s\n", ft_strncat(s1, s2, 3));
}
