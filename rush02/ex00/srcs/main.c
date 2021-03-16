/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:09:36 by jeyoon            #+#    #+#             */
/*   Updated: 2021/03/14 22:52:57 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int				g_error;

int	print_error(void)
{
	if (g_error == 1)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	else if (g_error == 2)
	{
		ft_putstr("error\n");
		return (1);
	}
	else if (g_error == 3)
	{
		ft_putstr("memory error\n");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_key_value	**dict_arr;
	char		buff[2000];

	g_error = 0;
	if (ac == 2)
	{
		dict_arr = make_dict("numbers.dict", buff, 0, 0);
		error_num(av[1]);
		if (print_error())
			return (0);
		cut_section(av[1], dict_arr);
		get_free(dict_arr);
	}
	else if (ac == 3)
	{
		dict_arr = make_dict(av[1], buff, 0, 0);
		error_num(av[2]);
		if (print_error())
			return (0);
		cut_section(av[2], dict_arr);
		get_free(dict_arr);
	}
	else
		return (0);
}
