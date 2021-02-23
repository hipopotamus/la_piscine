/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:15:56 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/23 13:11:01 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char alpha_z;

	alpha_z = 'z';
	while (alpha_z >= 'a')
	{
		write(1, &alpha_z, 1);
		alpha_z--;
	}
}
