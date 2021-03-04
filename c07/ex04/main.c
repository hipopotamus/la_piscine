#include <stdio.h>

char* ft_convert_base(char *nbr, char *base_from, char* base_to);

int main()
{
	char s[80] = "	 -++----12#213";
	printf("%s\n", ft_convert_base(s, "0123456789", "0123456789ABCDEF"));
}
