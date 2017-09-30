/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:04:54 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:51:54 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrsplit(char c, char *ref)
{
	if (ft_strchr(ref, c) != NULL)
		return (1);
	return (0);
}

int		ft_count_cases(char *str, char *ref)
{
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_chrsplit(str[i + 1], ref) == 0 || str[i + 1] == '\0')
				&& ft_chrsplit(str[i], ref) == 1)
			counter++;
		i++;
	}
	if (ft_strchr(ref, str[i - 1]) == NULL)
		counter++;
	return (counter);
}

char	*ft_copy(char *str, int deb, int l)
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

char	**ft_fill_tab(char **tab, char *str, char *charset)
{
	int i;
	int len;
	int tabi;

	i = 0;
	tabi = 0;
	while (str[i] != '\0')
	{
		len = 0;
		while (ft_strchr(charset, str[i]) == NULL)
		{
			len++;
			i++;
		}
		if (ft_strchr(charset, str[i]) != NULL && len > 0)
		{
			tab[tabi] = ft_copy((char*)str, i - len, len);
			tabi++;
		}
		i++;
	}
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;

	if (str == NULL || charset == NULL)
		return (NULL);
	if ((tab = (char**)malloc(sizeof(char*) * ft_count_cases(str, charset) + 1))
			== NULL)
		return (NULL);
	tab[ft_count_cases(str, charset)] = 0;
	tab = ft_fill_tab(tab, str, charset);
	return (tab);
}
