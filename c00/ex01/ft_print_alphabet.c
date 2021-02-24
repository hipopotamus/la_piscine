/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:11:40 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/25 02:58:23 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char alpha_a;

	alpha_a = 'a';
	while (alpha_a <= 'z')
	{
		write(1, &alpha_a, 1);
		alpha_a++;
	}
}
