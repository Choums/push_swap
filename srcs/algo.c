/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 07:59:42 by root              #+#    #+#             */
/*   Updated: 2022/02/20 15:34:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	tmp  = (*head);
	while (tmp->content != current)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}


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
	ft_push_b(head_a, head_b);
}