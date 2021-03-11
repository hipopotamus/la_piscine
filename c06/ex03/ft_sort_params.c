/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:17:06 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/11 15:42:39 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_sort(char **str, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < size - 1)
		{
			if (ft_strcmp(str[j], str[j + 1]) > 0)
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

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

int		main(int argc, char **argv)
{
	int i;

	ft_sort(argv + 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		print_str(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
