/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:28:56 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/16 12:31:23 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_atoi_base(char *str, char *base, int len);
int		check_base(char *base);

int		len_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		len_int_base(int num, char *base)
{
	int j;
	int len;

	len = len_str(base);
	j = 0;
	if (num < 0)
		j = 1;
	while (num != 0)
	{
		num = num / len;
		j++;
	}
	return (j - 1);
}

void	convert(int num, char *base, char *dest, int i_len)
{
	int		len;
	long	temp;

	temp = num;
	len = len_str(base);
	if (temp == 0)
		return ;
	if (temp < 0)
	{
		temp = -temp;
		dest[0] = '-';
	}
	convert(temp / len, base, dest, i_len - 1);
	dest[i_len] = base[temp % len];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_len;
	char	*ptr;
	int		num;
	int		int_len;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	base_len = len_str(base_from);
	num = ft_atoi_base(nbr, base_from, base_len);
	if (num == 0)
	{
		ptr = malloc(sizeof(char) * 2);
		ptr[0] = base_to[0];
		ptr[1] = '\0';
		return (ptr);
	}
	int_len = len_int_base(num, base_to);
	ptr = malloc(sizeof(char) * (int_len + 1));
	convert(num, base_to, ptr, int_len);
	ptr[int_len + 1] = '\0';
	return (ptr);
}
