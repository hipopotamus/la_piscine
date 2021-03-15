/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:01:40 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/15 15:30:15 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\f')
		return (1);
	if (c == '\r' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (check_space(base[i]))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (i);
}

int		check_in_base(char c, char *base)
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

int	ft_atoi_base(char *str, char *base, int len)
{
	int		i;
	int		plus_minus;
	int		res;
	int		sub;

	plus_minus = 1;
	i = 0;
	res = 0;
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
		if ((sub = check_in_base(str[i], base)) == -1)
			break ;
		res *= len;
		res += sub;
		i++;
	}
	return (plus_minus * res);
}
