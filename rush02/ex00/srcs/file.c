/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:53:26 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/14 22:53:07 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void		get_struct_sub(t_key_value *t[], int j)
{
	t[j]->key = (char*)malloc(sizeof(char) * 5);
	if (t[j]->key == NULL)
	{
		g_error = 3;
		return ;
	}
	ft_strncpy(t[j]->key, "null", 4);
	t[j]->value = (char*)malloc(sizeof(char) * 5);
	if (t[j]->value == NULL)
	{
		g_error = 3;
		return ;
	}
	ft_strncpy(t[j]->value, "null", 4);
}

void		get_struct(char *str, int i, t_key_value *t[], int j)
{
	int l_key;
	int l_value;

	l_key = len_kv(&str[i], 1);
	if (l_key == 0)
	{
		get_struct_sub(t, j);
		return ;
	}
	t[j]->key = (char*)malloc(sizeof(char) * (l_key + 1));
	if (t[j]->key == NULL && (g_error = 10))
		return ;
	ft_strncpy(t[j]->key, &str[i], l_key);
	t[j]->len = l_key;
	i += l_key;
	while (check_space(str[i]) == 1 || str[i] == ':')
		i++;
	l_value = len_kv(&str[i], 0);
	t[j]->value = (char*)malloc(sizeof(char) * (l_value + 1));
	if (t[j]->value == NULL)
	{
		g_error = 3;
		return ;
	}
	ft_strncpy(t[j]->value, &str[i], l_value);
}

int			get_file(char *buff, char *name)
{
	int file;
	int readn;

	file = open(name, O_RDONLY);
	if (file < 0)
	{
		g_error = 3;
		return (0);
	}
	readn = read(file, buff, 2000);
	buff[readn + 1] = '\0';
	return (readn);
}

t_key_value	**make_get(int size)
{
	t_key_value	**dict;
	int			i;

	dict = (t_key_value**)malloc(sizeof(t_key_value*) * (size + 1));
	if (dict == NULL)
	{
		g_error = 3;
		return (0);
	}
	i = 0;
	while (i < size + 1)
	{
		dict[i] = (t_key_value*)malloc(sizeof(t_key_value));
		if (dict[i] == NULL)
		{
			g_error = 3;
			return (0);
		}
		i++;
	}
	return (dict);
}

t_key_value	**make_dict(char *name, char *buff, int i, int j)
{
	int			len_e;
	int			readn;
	t_key_value	**dict;

	readn = get_file(buff, name);
	len_e = len_entry(buff) + 1;
	dict = make_get(len_e);
	if (g_error == 3)
		return (0);
	while (i < readn)
	{
		get_struct(buff, i, dict, j);
		if (g_error == 3)
			return (0);
		i += (len_kv(&buff[i], 0) + 1);
		j++;
	}
	dict[j]->key = (char*)malloc(sizeof(char) * 1);
	if (dict[j]->key == NULL)
	{
		g_error = 3;
		return (0);
	}
	dict[j]->key[0] = '\0';
	return (dict);
}
