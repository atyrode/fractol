/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:48:14 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 19:48:17 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(int n)
{
	int x;

	x = 1;
	if (n < 0)
	{
		x++;
		n = n * (-1);
	}
	while (n >= 10)
	{
		n = n / 10;
		x++;
	}
	return (x);
}

static char	*ft_itoa_neg(int n, char *str, int tot)
{
	int i;

	i = tot - 1;
	if (n < -2147483647)
	{
		str = (ft_strdup("-2147483648"));
		return (str);
	}
	n = n * -1;
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[0] = '-';
	str[tot] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		tot;

	tot = ft_len_int(n);
	i = tot - 1;
	if ((str = (char*)malloc(sizeof(char) * (tot + 1))) == NULL)
		return (NULL);
	if (n < 0)
	{
		str = ft_itoa_neg(n, str, tot);
		return (str);
	}
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[tot] = '\0';
	return (str);
}
