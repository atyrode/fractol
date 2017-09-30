/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:09:08 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:09:09 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_c(char *str, char c)
{
	int count;
	int i;
	int flag;

	flag = 0;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			flag = 0;
		}
		else if (str[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

static char	*ft_copy(char *str, int deb, int l)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(sizeof(char) * (l + 1));
	if (res == NULL)
		return (NULL);
	res[l] = '\0';
	while (i < l)
	{
		res[i] = str[deb + i];
		i++;
	}
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		taille;
	int		idx;

	idx = -1;
	i = 0;
	if (s == NULL)
		return (NULL);
	if ((tab = (char**)malloc(sizeof(char*) * (ft_c((char*)s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		taille = 0;
		while (s[i] != c && s[i] != '\0')
		{
			taille++;
			i++;
		}
		tab[++idx] = ft_copy((char*)s, i - taille, taille);
	}
	tab[ft_c((char*)s, c)] = 0;
	return (tab);
}
