#include <stdio.h>
#include <string.h>

char *ft_strcpy(char *dest, char *src);

int main()
{
	char s1[80];
	ft_strcpy(s1, "hellow");
	printf("%s", s1);
}
