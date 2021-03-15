/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:45:41 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/15 23:21:41 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_sep(char c, char* charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		len_str(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] != '\0' && check_sep(str[i], charset) == 0)
		i++;
	return (i);
}

int		len_words(char *str, char *charset)
{
	int i;
	int cnt;
	
	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (check_sep(str[i], charset) == 0)
		{
			cnt++;
			i += len_str(&str[i], charset);
		}
		else
			i++;
	}
	return (cnt);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**ptr;
	char	len;
	int		ptr_i;
	int		str_i;

	ptr = (char**)malloc(sizeof(char*) * (len_words(str, charset) + 1));
	ptr_i = 0;
	str_i = 0;
	while (str[str_i] != '\0')
	{
		if (check_sep(str[str_i], charset) == 0)
		{
			len = len_str(&str[str_i], charset);
			ptr[ptr_i] = (char*)malloc(sizeof(char) * (len + 1));
			ft_strncpy(ptr[ptr_i], &str[str_i], len);
			ptr_i++;
			str_i += len;
		}
		else
			str_i++;
	}
	ptr[ptr_i] = 0;
	return (ptr);
}
