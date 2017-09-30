/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:02:55 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:02:56 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned long int	i;
	unsigned char		*dest2;
	unsigned char		*src2;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	i = 0;
	while (i < num)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
