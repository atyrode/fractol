/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:08:16 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:08:17 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *cpy, char *src, size_t num)
{
	unsigned int	i;

	i = 0;
	while (i < num)
	{
		if (src[i] == '\0')
		{
			while (i < num)
			{
				cpy[i] = '\0';
				i++;
			}
		}
		else
		{
			cpy[i] = src[i];
			i++;
		}
	}
	return (cpy);
}
