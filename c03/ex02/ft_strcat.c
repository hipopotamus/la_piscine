char *ft_strcat(char *dest, char *src)
{
	int i;
	int size;

	size = 0;
	while(dest[i] != '\0')
		size++;

	i = 0;
	while(src[i] != '\0' && dest[size + i] != '\0')
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size +i] = '\0';
	return(dest);
}
