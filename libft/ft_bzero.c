/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:45:16 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 19:45:20 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	unsigned long int	i;
	char				*str;
	int					value;

	str = ptr;
	value = 0;
	i = 0;
	while (i < num)
	{
		str[i] = value;
		i++;
	}
}
