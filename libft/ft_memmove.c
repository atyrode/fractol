/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:03:21 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:03:22 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*cdest;
	unsigned char	*csrc;

	cdest = (unsigned char*)dest;
	csrc = (unsigned char*)src;
	if (cdest < csrc)
		return (ft_memcpy(dest, src, num));
	while (num > 0)
	{
		cdest[num - 1] = csrc[num - 1];
		num--;
	}
	return (dest);
}
