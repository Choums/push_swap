/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:10:06 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/15 08:14:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*elem;
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	elem = ft_lstnew((*f)(lst->content));
	if (!elem)
	{
		ft_lstclear(&new_lst, del);
		return (NULL);
	}
	new_lst = elem;
	lst = lst->next;
	while (lst)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (!elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}
