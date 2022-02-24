/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:37:38 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/24 11:03:35 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_a(t_list **head_a)
{
	int	tmp;

	if (!(*head_a) || !(*head_a)->next)
		return ;
	tmp = (*head_a)->content;
	(*head_a)->content = (*head_a)->next->content;
	(*head_a)->next->content = tmp;
	ft_print(SA);
}

void	ft_swap_b(t_list **head_b)
{
	int	tmp;

	if (!(*head_b) || !(*head_b)->next)
		return ;
	tmp = (*head_b)->content;
	(*head_b)->content = (*head_b)->next->content;
	(*head_b)->next->content = tmp;
	ft_print(SB);
}

void	ft_swap_ss(t_list **head_a, t_list **head_b)
{
	ft_swap_a(head_a);
	ft_swap_b(head_b);
}

void	ft_push_b(t_list **head_a, t_list **head_b)
{
	if (*head_a == NULL)
		return ;
	else if (*head_b) //Cas de maillons présent dans B
	{
		(*head_b)->previous = (*head_a);
		if (!((*head_a)->next == NULL)) //Cas où A n'a qu'un maillon
			(*head_a)->next->previous = NULL;
		*head_a = (*head_a)->next;
		(*head_b)->previous->next = (*head_b);
		*head_b = (*head_b)->previous;
	}
	else if (*head_b == NULL) //Cas où B n'a pas encore de maillon (init)
	{
		*head_b = (*head_a);
		if (!((*head_a)->next == NULL)) //Cas où A n'a qu'un maillon
			(*head_a)->next->previous = NULL;
		*head_a = (*head_b)->next;
		(*head_b)->next = NULL;
	}
	ft_print(PB);
}

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
