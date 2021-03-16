/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:54:02 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/16 12:57:15 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_nbr(int n)
{
	char a;

	if (n == 0)
		return ;
	print_nbr(n / 10);
	a = '0' + (n % 10);
	write(1, &a, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		print_str(par[i].str);
		write(1, "\n", 1);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			print_nbr(par[i].size);
		write(1, "\n", 1);
		print_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
