/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:08:45 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:08:47 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str1, char *str2, size_t num)
{
	unsigned int	i;

	i = ft_strlen(str2);
	if (*str2 == '\0')
		return (str1);
	while (*str1 != '\0' && num >= i)
	{
		if (*str1 == *str2 && ft_memcmp(str1, str2, i) == 0)
			return (str1);
		str1++;
		num--;
	}
	return (NULL);
}
