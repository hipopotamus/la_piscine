#include <unistd.h>

int check_alpha(char *str, int i)
{
	if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		return (1);
	return (0);
}

int check_word_head(char *str, int i)
{
	if (i == 0)
		return (1);
	else if (check_alpha(str, i - 1) == 0)
	{
		if(str[i - 1] < '0' || str[i - 1] > '9')
				return (1);
	}
	return (0);
}
	

void make_up(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - ('a' - 'A');
}

void make_low(char *str, int i)
{
	if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] = str[i] + ('a' - 'A');
}

char *ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (check_alpha(str, i))
		{
			if (check_word_head(str, i))
				make_up(str, i);
			else
				make_low(str,i);
		}
		i++;
	}
	return (str);
}

int main()
{
	char a[13] = "salut, cpommt";
	write(1, ft_strcapitalize(a), 14);
}
