/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:37:38 by chaidel           #+#    #+#             */
/*   Updated: 2022/01/25 14:39:11 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_init_stack(char **value, int size)
{
	size_t	i;
	t_list	*tmp;

	i = 1;
	tmp = ft_lstnew(value[i]);
	if (!tmp)
		ft_err();
	while (++i <= (size_t)size)
	{
		ft_lstadd_back(&tmp, ft_lstnew(value[i]));
		if (!tmp)
			ft_err();
	}
	return (tmp);
}

void	ft_swap_a(t_list **head_a)
{
	char	*tmp;

	if (!(*head_a)->content || !(*head_a)->next->content)
		return ;
	tmp = (*head_a)->content;
	(*head_a)->content = (*head_a)->next->content;
	(*head_a)->next->content = tmp;
	ft_print(SA);
}

void	ft_swap_b(t_list **head_b)
{
	char	*tmp;

	if (!(*head_b)->content || !(*head_b)->next->content)
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
	if (*head_b) //Cas de maillons present dans B
	{
		(*head_b)->previous = (*head_a);
		(*head_a)->next->previous = NULL;
		*head_a = (*head_a)->next;
		(*head_b)->previous->next = (*head_b);
		*head_b = (*head_b)->previous;
	}
	else //Cas ou B n'a pas encore de maillon (init)
	{
		*head_b = (*head_a);
		(*head_a)->next->previous = NULL;
		*head_a = (*head_b)->next;
		(*head_b)->next = NULL;
	}
	ft_print(PB);
}
