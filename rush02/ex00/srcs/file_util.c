/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:53:26 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/14 22:12:47 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int			check_space(char c)
{
	if (c == '\t' || c == '\t' || c == '\v')
		return (1);
	if (c == '\r' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

void		ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int			len_kv(char *str, int signal)
{
	int i;

	i = 0;
	if (signal == 1)
	{
		while (check_space(str[i]) == 0 && str[i] != ':')
			i++;
	}
	if (signal == 0)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
	}
	return (i);
}

int			len_entry(char *str)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			cnt++;
		i++;
	}
	return (cnt);
}

void		get_free(t_key_value **dict)
{
	int i;

	i = 0;
	while ((dict[i]->key)[0])
	{
		free(dict[i]->key);
		free(dict[i]->value);
		free(dict[i]);
		i++;
	}
	free(dict[i]->key);
	free(dict[i]);
	free(dict[i + 1]);
	free(dict);
}
