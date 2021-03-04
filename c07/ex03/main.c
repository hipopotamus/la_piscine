#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main()
{
	char **s1 = malloc(sizeof(char*) * 2);
	s1[0] = malloc(sizeof(char) * 5);
	s1[1] = malloc(sizeof(char) * 5);
	s1[0] = "hey";
	s1[1] = "boy";
	printf("%s\n", ft_strjoin(2, s1, ", "));
}
