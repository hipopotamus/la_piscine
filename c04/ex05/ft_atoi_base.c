/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:08:52 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/09 19:48:57 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\f')
		return (1);
	if (c == '\r' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int		except(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		if (check_space(str[i]))
			return (0);
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (i);
}

int		check(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi(char *str, char *base, int len)
{
	int i;
	int plus_minus;
	int res;
	int sub;

	plus_minus = 1;
	res = 0;
	i = 0;
	while (check_space(str[i]) != '\0')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			plus_minus *= -1;
		i++;
	}
	while (1)
	{
		if ((sub = check(str[i], base)) == -1)
			break ;
		res *= len;
		res += sub;
		i++;
	}
	return (plus_minus * res);
}

int		ft_atoi_base(char *str, char *base)
{
	int len;
	int res;

	len = except(base);
	if (len == 0)
		return (0);
	res = ft_atoi(str, base, len);
	return (res);
}
