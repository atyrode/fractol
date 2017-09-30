/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:08:06 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:08:07 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t num)
{
	unsigned int i;

	i = 0;
	if (num == 0)
		return (0);
	if (s1[i] == '\0' || s2[i] == '\0')
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	while (s1[i] != '\0' && s2[i] != '\0' && i < num)
	{
		if (s1[i] - s2[i] == 0)
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	if (i == num)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
