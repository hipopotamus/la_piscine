#include <unistd.h>
void convert_hex_print(char c)
{
	char *set;
	set = "0123456789abcdef";

	write(1, "\\", 1);
	write(1, &set[c/16%16], 1);
	write(1, &set[c%16], 1);
}

void ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			convert_hex_print(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int main(void)
{
	char a[10] = "adsdf\ndfdf";
	ft_putstr_non_printable(a);
}
