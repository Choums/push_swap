/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_stack_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:25:18 by root              #+#    #+#             */
/*   Updated: 2022/02/11 13:00:08 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_a(t_list **head_a, t_list **head_b)
{
	if (*head_b == NULL)
		return ;
	if (*head_a)
	{
		(*head_a)->previous = (*head_b);
		if (!((*head_b)->next == NULL)) //Cas où B n'a qu'un maillon
			(*head_b)->next->previous = NULL;
		*head_b = (*head_b)->next;
		(*head_a)->previous->next = (*head_a);
		*head_a = (*head_a)->previous;
	}
	else
	{
		*head_a = (*head_b);
		if (!((*head_b)->next == NULL)) //Cas où B n'a qu'un maillon
			(*head_b)->next->previous = NULL;
		*head_b = (*head_a)->next;
		(*head_a)->next = NULL;
	}
	ft_print(PA);
}

void	ft_rotate_a(t_list **head_a)
{
	t_list	*lst;
	void	*swap;
	int		size;

	size = ft_lstsize((*head_a));
	lst =  ft_lstlast((*head_a));
	swap = (*head_a)->content;
	(*head_a)->content = lst->content;
	lst->content = swap;
	lst = lst->previous;
	if (size % 2 == 0)
		size--;
	while (size / 2 > 0)
	{
		swap = lst->previous->content;
		lst->previous->content = lst->content;
		lst->content = swap;
		lst = lst->previous->previous;
		size--;
	}
	ft_print(RA);
}

void	ft_rotate_b(t_list **head_b)
{
	// t_list	*tmp;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize((*head_b));
	ft_print(RB);
}

void	ft_rotate_rr(t_list **head_a, t_list **head_b)
{
	ft_rotate_a(head_a);
	ft_rotate_b(head_b);
	ft_print(RR);
}
