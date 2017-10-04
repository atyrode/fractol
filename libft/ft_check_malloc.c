/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 21:21:48 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/02 21:22:46 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_check_malloc(void *assertion)
{
	if (!assertion)
	{
		ft_putstr("Fatal: Memory allocation error\n");
		exit(2);
	}
	return (assertion);
}
