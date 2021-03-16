/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_section.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:10:16 by jeyoon            #+#    #+#             */
/*   Updated: 2021/03/14 22:56:27 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char g_section[3];

void	init_section(void)
{
	g_section[0] = '0';
	g_section[1] = '0';
	g_section[2] = '0';
}

void	cut_section(char *number, t_key_value **dict_arr)
{
	int len;
	int i;

	len = ft_strlen(number);
	if (len == 1 && number[0] == '0')
	{
		print_zero(dict_arr);
		return ;
	}
	i = 0;
	while (len > 0)
	{
		init_section();
		fill_section(number, len, &i);
		read_section(dict_arr);
		if (g_section[0] != '0' || g_section[1] != '0' || g_section[2] != '0')
			print_digit(i, number, dict_arr);
		if (len % 3 == 0)
			len -= 3;
		else
			len -= (len % 3);
		if (len <= 0)
			ft_putstr("\n");
	}
}

void	fill_section(char *number, int len, int *i)
{
	int section_idx;

	if (len % 3 == 0)
	{
		g_section[0] = number[(*i)++];
		g_section[1] = number[(*i)++];
		g_section[2] = number[(*i)++];
	}
	else
	{
		section_idx = 3 - (len % 3);
		while (section_idx < 3)
		{
			g_section[section_idx] = number[(*i)++];
			section_idx++;
		}
	}
}

void	print_digit(int idx, char *number,
		t_key_value **dict_arr)
{
	int len;
	int i;
	int temp;

	temp = idx;
	len = 1;
	while (number[idx++])
		len++;
	if (len < 3)
		return ;
	i = 0;
	while (dict_arr[i]->key)
	{
		if (print_digit2(number, dict_arr[i], temp, len))
			return ;
		i++;
	}
}

int		print_digit2(char *number, t_key_value *dict_element, int temp, int len)
{
	int j;

	if (len == dict_element->len)
	{
		if (len == dict_element->len)
		{
			j = 1;
			while (dict_element->key[0] == '1' && dict_element->key[j] == '0'
					&& j < len)
				j++;
			if (dict_element->key[j] == '\0')
			{
				ft_putstr(" ");
				ft_putstr(dict_element->value);
				if (check_zero(&number[temp]) == 0)
				{
					ft_putstr(" ");
					return (1);
				}
			}
		}
	}
	return (0);
}
