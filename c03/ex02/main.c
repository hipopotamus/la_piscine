#include <stdio.h>

char *ft_strcat(char *dest, char *src);

int main()
{
	char s1[80] = "hellow";
	char s2[7] = "abcdef";

	printf("%s\n", ft_strcat(s1, s2));
}
