/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_stack_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:25:18 by root              #+#    #+#             */
/*   Updated: 2022/02/12 09:05:57 by root             ###   ########.fr       */
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
	t_list	*tmp;
	void	*swap;
	int		size;
	
	if (!(*head_a))
		return ;
	tmp = (*head_a);
	size = ft_lstsize((*head_a));
	while (size - 1 > 0)
	{
		swap = tmp->next->content;
		tmp->next->content = tmp->content;
		tmp->content = swap;
		tmp = tmp->next;
		size--;
	}
	ft_print(RA);
}

void	ft_rotate_b(t_list **head_b)
{
	t_list	*tmp;
	void	*swap;
	int		size;

	tmp = (*head_b);
	size = ft_lstsize((*head_b));
	while (size - 1)
	{
		swap = tmp->next->content;
		tmp->next->content = tmp->content;
		tmp->content = swap;
		tmp = tmp->next;
		size--;
	}
	ft_print(RB);
}

void	ft_rotate_rr(t_list **head_a, t_list **head_b)
{
	ft_rotate_a(head_a);
	ft_rotate_b(head_b);
	ft_print(RR);
}
