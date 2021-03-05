#include <stdio.h>

char** ft_split(char* str, char* charset);

int main()
{
	int i;

	i = 0;
	char **s = ft_split("hello,w,my,+name", ",+");
	while(i < 4)
	{
		printf("%s\n", s[i]);
		i++;
	}
}
