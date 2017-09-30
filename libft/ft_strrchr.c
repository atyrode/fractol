/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:08:58 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:09:00 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int value)
{
	int		i;
	char	*p;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == value)
		{
			p = &str[i];
			return (p);
		}
		i--;
	}
	return (NULL);
}
