#include <stdio.h>

char** ft_split(char* str, char* charset);

int main()
{
	int i;

	i = 0;
	char **s = ft_split("&&cde&&", "&!");
	while(s[i] != '\0')
	{
		printf("%s\n", s[i]);
		i++;
	}
}
