#include <stdio.h>

unsigned int  ft_strlcat(char *dest, char *src, unsigned int size);

int main()
{
	char s1[6] = "hellow";
	char s2[7] = "abc";

	printf("%u\n", ft_strlcat(s1, s2, 6));
	printf("%s\n", s1);
}
