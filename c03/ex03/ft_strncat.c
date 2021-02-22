char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int size;
	int i;

	size = 0;
	while(dest[size] != '\0')
		size++;

	i = 0;
	while(i < nb && src[i] != '\0')
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size +i] = '\0';
	return (dest);
}
