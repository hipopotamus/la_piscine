/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 02:56:26 by sungwopa          #+#    #+#             */
/*   Updated: 2021/02/25 02:56:29 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
