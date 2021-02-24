/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 03:28:44 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/25 05:51:19 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	buff[10];

void	print_combn(int n, int i, int j)
{
	if (j == 0)
	{
		write(1, buff, n);
		if (buff[0] != '0' + 10-n)
			write(1, ", ", n);
	}

	while (n - j + i <= 10 - j && j != 0)
	{
		buff[n - j] = '0' + n - j + i;
		print_combn(n, i, j - 1);
		i++;
	}
}

void	ft_print_combn(n)
{
	int i;
	int j;

	i = 0;
	j = n;

	print_combn(n, i, j);
}
