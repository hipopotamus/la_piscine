/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:09:48 by jeyoon            #+#    #+#             */
/*   Updated: 2021/03/14 22:45:51 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <unistd.h>

int		ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	if (str1[i] == str2[i] && str1[i] == '\0')
		return (1);
	else
		return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		find_key(char c, char *str)
{
	int len;

	len = ft_strlen(str);
	if (len != 1)
		return (0);
	if (str[0] == c && str[1] == '\0')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	error_num(char *number)
{
	int len;

	len = 0;
	if (number[0] == '0' && number[1] != '\0')
	{
		g_error = 2;
	}
	while (number[len] != '\0')
	{
		if (number[len] < '0' || number[len] > '9')
		{
			g_error = 2;
			return ;
		}
		len++;
	}
	if (len >= 40)
		g_error = 1;
}
