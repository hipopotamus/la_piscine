#include <unistd.h>

int ft_str_is_alpha(char *str)
{
	int i;
	
	i = 0;
	while(str[i] != '\0')
	{
		if((str[i] < 'a' || 'z' < str[i]) && (str[i] < 'A' || 'Z' < str[i]))
			return (0);
		i++;
	}
	return (1);
}

int main()
{
	char a = '0' + ft_str_is_alpha("ADj");
	write(1, &a, 1);
}
