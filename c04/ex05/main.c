#include <stdio.h>

int ft_atoi_base(char *str, char *base);

int main()
{
	char s1[80] = "		-+1134141d";
	printf("%d\n", ft_atoi_base(s1, "0123456789ABCDEF"));
}
