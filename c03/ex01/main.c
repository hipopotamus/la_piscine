#include <stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
	char s1[8] = "abcdefg";
	char s2[8] = "abcdedg";

	printf("%d\n", ft_strncmp(s1, s2, 6));
}
