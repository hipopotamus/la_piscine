/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:51:44 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/09 18:55:15 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_rev_str(char *str, int i)
{
	if (str[i] == '\0')
		return ;
	print_rev_str(str, i + 1);
	write(1, &str[i], 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		print_rev_str(argv[i], 0);
		write(1, "\n", 1);
		i++;
	}
}
