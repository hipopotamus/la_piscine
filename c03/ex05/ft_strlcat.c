/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:22:48 by sungwopa          #+#    #+#             */
/*   Updated: 2021/03/11 13:38:35 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int len_dest;
	unsigned int len_src;
	unsigned int i;

	len_dest = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	i = 0;
	while (size > len_dest + 1 && src[i] != '\0' && i < size - len_dest - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	if (size < len_dest)
		return (size + len_src);
	return (len_dest + len_src);
}
