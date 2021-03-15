#include <stdio.h>
#include <stdlib.h>

char* ft_convert_base(char *nbr, char *base_from, char* base_to);

int main()
{
	int i;

	i = 0;
	while(i < 10)
	{
		char s[80] = "80000001";
		printf("%s\n", ft_convert_base(s, "0123456789abcdef", "0123456789"));
		printf("atoi : %d\n", atoi(s));
		i++;
	}
}
