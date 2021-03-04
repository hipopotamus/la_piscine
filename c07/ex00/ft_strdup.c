#include <stdlib.h>

int len_str(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char *dest = malloc(sizeof(char) * len_str(src));
	dest = src;
	return (dest);
}
