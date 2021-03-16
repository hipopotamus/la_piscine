/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:24:01 by jeyoon            #+#    #+#             */
/*   Updated: 2021/03/14 23:04:35 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		check_zero(char *number)
{
	int i;

	i = 0;
	while (number[i] != '\0')
	{
		if (number[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	print_zero(t_key_value **dict_arr)
{
	int i;

	i = 0;
	while (dict_arr[i]->key)
	{
		if (find_key('0', dict_arr[i]->key))
			ft_putstr(dict_arr[i]->value);
		i++;
	}
}
