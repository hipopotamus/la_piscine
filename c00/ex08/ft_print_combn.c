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

void convert(int n, int size)
{
	char buff[size];
	int i;

	i = -1;
	if (n == 0)
		return ;
	while(++i <= size - 1)
	{
		if (n / power(10, size -1 - i) < 1)
			buff[i] = '0';
		else
			buff[i] = '0' + n / power(10, size - 1 - i);
		n = n % power(10, size - 1 - i);
	}
	write(1, buff, size);
}

int check(int n, int size)
{
	int i;

	i = -1;
	while(++i < size - 1)
	{
		if(n / power(10 , size - 1 - i) > n % power(10 , size - 1 - i) / power(10 , size - 2 - i))
			return (2);
		else
			return (3);
		n = n % power(10, size - 1 - i);
	}
}

void ft_print_combn(int n)
{
	int i;
	
	i = 0;
	while(++i < power(10, n) - 1)
	{
		if (check(i, n) == 3)
		{
			convert(i,n);
			write(1, ", ", 2);
		}
	}
}

int main()
{
	ft_print_combn(3);
}
