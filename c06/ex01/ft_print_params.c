#include <unistd.h>

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

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	while(i < argc)
	{
		print_str(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
