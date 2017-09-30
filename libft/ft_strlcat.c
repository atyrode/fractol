/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:07:03 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:07:04 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t num)
{
	size_t i;
	size_t len_dest;
	size_t len_src;

	i = 0;
	len_dest = (size_t)ft_strlen(dest);
	len_src = (size_t)ft_strlen(src);
	if (num == 0)
		return (len_src);
	if (num < len_dest)
		return (num + len_src);
	while (src[i] != '\0' && (len_dest + 1 + i) < num)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
