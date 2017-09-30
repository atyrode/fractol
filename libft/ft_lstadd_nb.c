/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:01:08 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:01:11 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ajouterenfin(t_list *lst, void const *content, size_t content_size)
{
	t_list *new;
	t_list *tmp;

	new = ft_lstnew(content, content_size);
	new->next = NULL;
	if (lst == NULL)
	{
		return (lst);
	}
	else
	{
		tmp = lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
		return (lst);
	}
}

t_list	*ft_lstadd_nb(t_list *lst, int nb,
		void const *content, size_t content_size)
{
	t_list	*current;
	int		i;

	i = 0;
	current = lst;
	while (i < nb)
	{
		current = ajouterenfin(lst, content, content_size);
		i++;
	}
	return (current);
}
