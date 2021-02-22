#include <unistd.h>

int ft(char *str)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while(str[i] != '\0')
	{
		if ((str[i] < 'a' || 'z' < str[i]) && (str[i] < 'A' || 'Z' < str[i]))
		{
			res = 0;
			break;
		}
		i++;
	}
	return(res);
}

int main()
{
	char a = '0' + ft("12321h");

	write(1, &a, 1);
}
