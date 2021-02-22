#include <unistd.h>

int power(int a, int b)
{
	int i;
	int temp;

	temp = a;
	i = 0;
	while(++i < b)
		a = a*temp;
	if (b == 0)
		return (1);
	return (a);
}

void convert(int n, int size, char buff[])
{
	int i;

	i = -1;
	while(++i <= size - 1)
	{
		if (n / power(10, size -1 - i) < 1)
			buff[i] = '0';
		else
			buff[i] = '0' + n / power(10, size - 1 - i);
		n = n % power(10, size - 1 - i);
	}
}

int check(char buff[], int size)
{
	int i;

	i = -1;
	while(++i < size - 1)
	{
		if(buff[i] >= buff[i+1])
			return(0);
	}
	return(1);
}

void ft_print_combn(int n)
{
	int i;
	char buff[n];
	char end = '0' + 10 - n;
	
	i = 0;
	while(i++ < power(10 , n) - 1)
	{
		convert(i, n, buff);
		if (check(buff, n) == 1)
		{
			write(1, buff, n);
			if (buff[0] != end)
				write(1, ", ", 2);
		}
	}
}

int main()
{
	ft_print_combn(2);
}
