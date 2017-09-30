/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:02:38 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:02:39 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	unsigned long int		i;
	unsigned char			*dest2;
	unsigned const char		*src2;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned const char*)src;
	i = 0;
	if (num == 0)
		return (NULL);
	while (i < num)
	{
		if ((char)src2[i] == (char)c)
		{
			dest2[i] = src2[i];
			return (dest2 + (i + 1));
		}
		else
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (NULL);
}
