/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_section.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:09:29 by jeyoon            #+#    #+#             */
/*   Updated: 2021/03/14 22:34:57 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

void	read_first(char first, t_key_value **dict_arr)
{
	int i;

	i = 0;
	while (dict_arr[i]->key)
	{
		if (find_key(first, dict_arr[i]->key))
		{
			ft_putstr(dict_arr[i]->value);
			ft_putstr(" ");
			break ;
		}
		i++;
	}
	while (dict_arr[i]->key)
	{
		if (ft_strcmp(dict_arr[i]->key, "100"))
		{
			ft_putstr(dict_arr[i]->value);
			if (g_section[1] != '0' || g_section[2] != '0')
				ft_putstr(" ");
			break ;
		}
		i++;
	}
}

void	read_second(char second, char third, t_key_value **dict_arr)
{
	int i;

	i = 0;
	if (second == '0')
	{
		read_third(third, dict_arr);
	}
	else if (second == '1')
	{
		while (dict_arr[i]->key)
		{
			if (dict_arr[i]->key[0] == second && dict_arr[i]->key[1] == third &&
					dict_arr[i]->key[2] == 0)
			{
				ft_putstr(dict_arr[i]->value);
				break ;
			}
			i++;
		}
	}
	else
	{
		read_second2(second, dict_arr);
		read_third(third, dict_arr);
	}
}

void	read_second2(char second, t_key_value **dict_arr)
{
	int i;

	i = 0;
	while (dict_arr[i]->key)
	{
		if (dict_arr[i]->key[0] == second && dict_arr[i]->key[1] == '0' &&
				dict_arr[i]->key[2] == 0)
		{
			ft_putstr(dict_arr[i]->value);
			if (g_section[2] != '0')
				ft_putstr(" ");
			break ;
		}
		i++;
	}
}

void	read_third(char third, t_key_value **dict_arr)
{
	int i;

	i = 0;
	while (dict_arr[i]->key && third != '0')
	{
		if (find_key(third, dict_arr[i]->key))
		{
			ft_putstr(dict_arr[i]->value);
			break ;
		}
		i++;
	}
}

void	read_section(t_key_value **dict_arr)
{
	int i;

	i = 0;
	if (g_section[0] != '0')
	{
		read_first(g_section[0], dict_arr);
	}
	read_second(g_section[1], g_section[2], dict_arr);
}
