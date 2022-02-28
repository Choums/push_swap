/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:32:03 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/28 09:06:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_big(t_list **head)
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
		if (current < tmp->content)
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

// void	ft_sorting(t_list **head_a, t_list **head_b)
// {
// 	int	size;
// 	int	max_num;
// 	int	pivot;

// 	size = ft_lstsize((*head_a));
// 	if (size <= 100)
// 		pivot = size - size / 10;
// 	else
// 		pivot = size - size / 5;
// 	while (pivot--)
// 	{
// 		ft_select(head_a, head_b);
// 		max_num = ft_get_big(head_a);
// 	}
// }

// void	ft_select(t_list **head_a, t_list **head_b)
// {
// 	int	size;
// 	int	pos;
// 	int	pivot;

// 	pos = ft_get_big(head_a);
// 	if (pos <= size / 2)
// 	{
// 		while (pos > 1 && size > 1)
// 		{
// 			ft_rotate_a(head_a);
// 			pos--;
// 		}
// 	}
// 	else
// 	{
// 		while (pos <= size && size > 1)
// 		{
// 			ft_rev_rotate_a(head_a);
// 			pos++;
// 		}
// 	}
// 	if ((*head_a)->next)
// 		ft_push_b(head_a, head_b);
// }
