#include <unistd.h>

int is_alpha(char c)
{
	if('a' <= c && c <= 'z')
		return(1);
	if ('A' <= c && c<= 'Z')
		return (1);
	return (0);
}

int ft(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (is_alpha(str[i++]))
			return(1);
	}
	return (0);
}

int main()
{
	char a = '0' + ft("213r");
	write(1, &a, 1);
}
