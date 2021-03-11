#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main()
{
	int size = 5;
	int str_size = 80;
	char **s1 = malloc(sizeof(char*) * size);
	int i = 0;

	//printf("%c\n", ft_strjoin(0, s1, ", ")[0]);
	while(i< size)
	{
		s1[i] = malloc(sizeof(char) * str_size);
		i++;
	}
	s1[0] = "dd";
	s1[1] = "boyd";
	s1[2] = "@!hdsfa";
	s1[3] = "adsf2132";
	s1[4] = "hello";
	printf("%s\n", ft_strjoin(size, s1, "|=_=_=|"));
}
