/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 21:54:47 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/02 21:54:52 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strjoin3(char *s1, char *s2, char *s3)
{
	size_t		s1len;
	size_t		s2len;
	size_t		s3len;
	char		*ret;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s3len = ft_strlen(s3);
	if (!(ret = (char*)malloc((s1len + s2len + s3len + 1) * sizeof(*ret))))
		return (NULL);
	ret[0] = '\0';
	ft_strcpy(ret, s1);
	ft_strcpy(ret + s1len, s2);
	ft_strcpy(ret + s1len + s2len, s3);
	return (ret);
}
