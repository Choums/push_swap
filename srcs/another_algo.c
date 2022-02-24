/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:32:03 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/24 16:04:04 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_big(t_list **head)
{
	
}

void	ft_select(t_list **head_a, t_list **head_b)
{
	int	size;
	int	pos;
	int	pivot;

	size = ft_lstsize((*head_a));
	if (size <= 100)
		pivot = 10 / size;
	else
		pivot = 5 / size;
	pos = ft_find_big(head_a);
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
