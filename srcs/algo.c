/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 07:59:42 by root              #+#    #+#             */
/*   Updated: 2022/02/25 17:45:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Works for 3 nums.
	By finding the smallest position,
	only a swap and a rev are needed for 2nd and 3rd num
*/

void	ft_lil_sort(t_list **head_a)
{
	int		size;
	int		pos;

	pos = ft_find_smol(head_a);
	size = ft_lstsize((*head_a));
	if (size == 2)
	{
		if ((*head_a)->content > (*head_a)->next->content)
			ft_swap_a(head_a);
	}
	else if (size == 3)
	{
		if (pos == 3)
			ft_rev_rotate_a(head_a);
		else if (pos == 2)
			ft_swap_a(head_a);
		if ((*head_a)->next->content > (*head_a)->next->next->content)
		{
			ft_rev_rotate_a(head_a);
			ft_swap_a(head_a);
		}
	}
}

/*
	Return:	position of the smallest on the stack
*/

int	ft_find_smol(t_list **head)
{
	t_list	*tmp;
	int		current;
	int		pos;

	pos = 1;
	tmp = (*head);
	current = tmp->content;
	tmp = tmp->next;
	while (tmp)
	{
		if (current > tmp->content)
			current = tmp->content;
		tmp = tmp->next;
	}
	tmp = (*head);
	while (tmp->content != current)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

/*
	Less than 50 nums, greedy on hits beyond
*/

void	ft_select_sort(t_list **head_a, t_list **head_b)
{
	int	iter;

	iter = ft_lstsize((*head_a));
	while (iter > 0)
	{
		ft_selective(head_a, head_b);
		iter--;
	}
	while ((*head_b))
		ft_push_a(head_a, head_b);
}

void	ft_selective(t_list **head_a, t_list **head_b)
{
	int	pos;
	int	size;

	pos = ft_find_smol(head_a);
	size = ft_lstsize((*head_a));
	if (pos <= size / 2)
	{
		while (pos > 1 && size > 1)
		{
			ft_rotate_a(head_a);
			pos--;
		}
	}
	else
	{
		while (pos <= size && size > 1)
		{
			ft_rev_rotate_a(head_a);
			pos++;
		}
	}
	if ((*head_a)->next)
		ft_push_b(head_a, head_b);
}
