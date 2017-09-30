/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:02:46 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:02:47 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char		*str;
	unsigned long int	i;
	void				*p;
	unsigned char		value2;

	i = 0;
	value2 = (unsigned char)value;
	str = (unsigned char*)ptr;
	while (i < num)
	{
		if ((unsigned char)str[i] == value2)
		{
			p = &str[i];
			return (p);
		}
		i++;
	}
	return (NULL);
}
