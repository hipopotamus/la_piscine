#include <stdio.h>
#include <string.h>

char ft_strncpy(char *dest, char *src, unsigned int n);

int main()
{
	char s1[80];
	
	s1[4] = '1';
	ft_strncpy(s1, "hellow", 4);
	printf("%s", s1);
}
