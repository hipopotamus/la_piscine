/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:02:46 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/09 19:51:19 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\f')
		return (1);
	if (c == '\r' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int i;
	int plus_minus;
	int res;

	plus_minus = 1;
	res = 0;
	i = 0;
	while (check_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			plus_minus *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (plus_minus * res);
}
