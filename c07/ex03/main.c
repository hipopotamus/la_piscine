#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main()
{
	char **s1 = malloc(sizeof(char*) * 2);
	s1[0] = malloc(sizeof(char) * 5);
	s1[1] = malloc(sizeof(char) * 5);
	s1[0] = "dd";
	s1[1] = "boyd";
	printf("%s\n", ft_strjoin(1, s1, ", "));
}
