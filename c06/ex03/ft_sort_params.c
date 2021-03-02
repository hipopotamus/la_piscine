#include <unistd.h>
#include <stdio.h>

int ft_len(char* str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

char *ft_sort(char *str)
{
	int i;
	int j;
	int temp;

	i = 0;
	while(str[i] != '\0')
	{
		j = 0;
		while(j < ft_len(str) - i - 1)
		{
			if (str[j] > str[j + 1])
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (str);
}

void print_str(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char** argv)
{
	int i;
	
	i = 1;
	while(i < argc)
	{
		print_str(ft_sort(argv[i]));
		write(1, "\n", 1);
		i++;
	}
}
