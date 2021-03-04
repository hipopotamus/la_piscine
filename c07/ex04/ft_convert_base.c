#include <stdlib.h>
#include <unistd.h>

long long ft_atoi_base(char *str, char *base, int len);
int check_base(char *base);

int len_str(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int len_int_base(long long num, char* base)
{
	int j;
	int len;

	len = len_str(base);
	j = 0;
	if (num < 0)
		j = 1;
	while(num != 0)
	{
		num = num/len;
		j++;
	}
	return(j - 1);
}

void convert(long long num, char *base, char* dest, int i_len)
{
	int len;

	len = len_str(base);
	if (num == 0)
		return ;
	if (num < 0)
	{
		num = -num;
		dest[0] = '-';
	}
	convert(num / len, base, dest, i_len - 1);
	dest[i_len] = base[num % len];
}

char* ft_convert_base(char *nbr, char* base_from, char *base_to)
{
	int base_len;
	char* ptr;
	long long num;
	int int_len;

	if(check_base(base_from) == 0 || check_base(base_to) == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	base_len = len_str(base_from);
	num = ft_atoi_base(nbr, base_from, base_len);
	int_len = len_int_base(num, base_to);
	ptr = malloc(sizeof(char) * int_len);
	convert(num, base_to, ptr, int_len);
	return(ptr);
}

