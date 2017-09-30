/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:44:13 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 19:44:18 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_without_special_char(char *str)
{
	int i;

	i = 0;
	if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\f' || str[i] == '\r')
		return (1);
	return (0);
}

int				ft_atoi(char *str)
{
	int i;
	int res;
	int negatif;

	i = 0;
	res = 0;
	negatif = 0;
	while (ft_without_special_char(str) == 1)
		str++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] < 48 || str[i + 1] > 57)
			return (0);
		if (str[i] == '-')
			negatif = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (negatif == 1)
		return (res * (-1));
	return (res);
}
