/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:06:18 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:06:19 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int x;

	if (s1 == NULL || s2 == NULL)
		return (0);
	x = ft_strcmp((char*)s1, (char*)s2);
	if (x == 0)
		return (1);
	return (0);
}
