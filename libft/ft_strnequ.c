/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:08:24 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:08:25 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int x;

	if (n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	x = ft_strncmp((char*)s1, (char*)s2, (int)n);
	if (x == 0)
		return (1);
	return (0);
}
