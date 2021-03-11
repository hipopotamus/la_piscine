/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:56:52 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/11 13:32:00 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		same(char *str_temp, char *find_temp)
{
	int i;

	i = 0;
	while (find_temp[i] != '\0')
	{
		if (str_temp[i] != find_temp[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (same(&str[i], to_find))
			return (&str[i]);
		i++;
	}
	return (0);
}

int main()
{
	printf("%s", ft_strstr("hellow", ""));
}
