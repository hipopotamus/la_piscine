#include <stdio.h>

void ft_putstr_non_printable(char *str);

int main()
{
	char s1[80] = "one!two@tree^for\nfive\"";
	ft_putstr_non_printable(s1);
}
