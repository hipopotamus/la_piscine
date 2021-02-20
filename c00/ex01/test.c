/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:02:38 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/18 19:08:46 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_print_alphabet(void)
{
	char c = 'a';
	
	int i = 0;

	while(i<26)
	{
		write(1, &c, 1);
		c++;
		i++;
	}
}

int main()
{
	ft_print_alphabet();
}
