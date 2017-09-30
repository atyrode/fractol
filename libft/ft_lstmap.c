/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:02:06 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/22 20:02:07 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	new = NULL;
	tmp = NULL;
	while (lst)
	{
		if (new == NULL)
		{
			new = f(lst);
			tmp = new;
		}
		else
		{
			new->next = f(lst);
			new = new->next;
		}
		lst = lst->next;
	}
	return (tmp);
}
