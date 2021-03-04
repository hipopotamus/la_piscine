#include <stdlib.h>

int check_sep(char c, char* charset)
{
	int i;

	i = 0;
	while(charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

void strncpy(char* dest, char* str, int n)
{
	int i;

	i = 0;
	while(str[i] != '\0' && i < n)
	{
		dest[i] = str[i];
	}
	dest[i] = '\0';
}

int len_word(char* str, char* charset)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (check_sep(str[i], charset) == 1)
			break;
		i++;
	}
	return (i);
}

int num_word(char* str, char* charset)
{
	int i;
	int num;

	while(str[i] != \'0')
	{
		if (check_sep(str[i], charset) == 0)
		{
			num++;
			i = i + len_word(&str[i], charset);
		}
		else
		{
			i++;
		}
	}
	return (num);
}

char** ft_split(char* str, char* charset)
{
	char **ptr;
	int ptr_i;
	int str_i;
	int word_len;

	ptr = (char**)malloc(sizeof(char*) * num_word(str, charset));
	ptr_i = 0;
	str_i = 0;
	while(str[str_i] != '\0')
	{
		if (check_sep(str[str_i], charset) == 0)
		{
			word_len = len_word(&str[str_i], charset);
			ptr[ptr_i] = (char*)malloc(sizeof(char) * word_len);
			strncpy(ptr[ptr_i], &str[str_i], word_len);
			ptr_i++;
			str_i += word_len;
		}
		else
		{
			str_i++;
		}
	}
	ptr[ptr_i] = 0;
	return (ptr);
}
