/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:27:37 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/09 21:43:23 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		len_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		len_strs(char **strs, int size)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + len_str(strs[i]);
		i++;
	}
	return (len);
}

void	ft_strcat(char *dest, char *str)
{
	int i;
	int len_dest;

	len_dest = len_str(dest);
	i = 0;
	while (str[i] != '\0')
	{
		dest[len_dest + i] = str[i];
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		i;
	int		len;

	if (size == 0)
	{
		ptr = (char*)malloc(sizeof(char) * 0);
		ptr[0] = '\0';
	}
	len = len_strs(strs, size);
	ptr = (char*)malloc(sizeof(char) * (len + 1 + len_str(sep) * (size - 1)));
	i = 0;
	while (i < size)
	{
		ft_strcat(ptr, strs[i]);
		if (i != size - 1)
			ft_strcat(ptr, sep);
		i++;
	}
	return (ptr);
}
