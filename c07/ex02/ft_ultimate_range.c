/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:22:48 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/10 16:16:32 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int len;
	int *ptr;

	len = (max - min);
	if (len <= 0)
	{
		range[0] = NULL;
		return (0);
	}
	ptr = (int*)malloc(sizeof(int) * len);
	if (ptr == 0)
		return (-1);
	i = 0;
	while (i < len)
	{
		ptr[i] = min + i;
		i++;
	}
	range[0] = ptr;
	return (len);
}
