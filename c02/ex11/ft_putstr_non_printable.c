/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 02:57:07 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/07 15:22:21 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert_hex_print(unsigned char c)
{
	char *set;

	set = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &set[c / 16], 1);
	write(1, &set[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			convert_hex_print(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
