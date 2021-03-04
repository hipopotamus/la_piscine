#include <stdio.h>

int ft_atoi_base(char *str, char *base);

int main()
{
	char s1[80] ="	+++-101";
	printf("%d\n", ft_atoi_base(s1, "01"));
}
