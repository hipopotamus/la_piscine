#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);

int main()
{
	ft_putchar('c');
	ft_putstr("\nhellow\n");
	printf("%d\n", ft_strlen("hellow"));
	printf("%d\n", ft_strcmp("he", "he"));
	return (0);
}

