#include <stdio.h>

void ft_ft(int *nbr);

int main()
{
	int n;
	n = 10;

	ft_ft(&n);
	printf("%d", n);
}
