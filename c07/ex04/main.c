#include <stdio.h>

char* ft_convert_base(char *nbr, char *base_from, char* base_to);

int main()
{
	int i;

	i = 0;
	while(i < 100)
	{
		char s[80] = "-2147483648";
		printf("%s\n", ft_convert_base(s, "0123456789", "0123456789"));
		i++;
	}
}
