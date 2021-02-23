/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:31:35 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/23 15:51:27 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_positive(int nb)
{
	char a;

	if (nb == 0)
		return ;
	print_positive(nb / 10);
	a = '0' + nb % 10;
	
	write(1, &a, 1);
}

void  ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		print_positive(-nb);
	}
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		print_positive(nb);
	}
}
