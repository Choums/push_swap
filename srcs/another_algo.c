/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:32:03 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/01 17:26:27 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_list **head_a, t_list **head_b)
{
	int	i;
	int	size;

	size = ft_lstsize((*head_a));
	i = 0;
	while (++i <= size)
		ft_get_final_pos(head_a, i);

	while ()
	{
		ft_select(head_a, head_b);
	}
}

void	ft_select(t_list **head_a, t_list **head_b)
{
	int		size;
	int		pivot;
	t_list	*tmp;

	size = ft_lstsize((*head_a));
	if (size <= 100)
		pivot = size - (size / 5 ) * i;
	else
		pivot = size - (size / 10) * i;
	tmp = (*head_a);
	while (tmp)
	{
		if (tmp->pos >= pivot)
		{
			ft_pusher(head_a, head_b, tmp->content);
			tmp = (*head_a);
		}
		else
			tmp = tmp->next;
	}
	while ((*head_b))
		ft_sortin_b(head_a, head_b);
}

void	ft_sortin_b(t_list **head_a, t_list **head_b)
{
	int	size;
	int	pos;

	size = ft_lstsize((*head_b));
	pos = ft_get_big(head_b);
	if (pos <= size / 2)
	{
		while (pos > 1 && size > 1)
		{
			ft_rotate_a(head_b);
			pos--;
		}
	}
	else
	{
		while (pos <= size && size > 1)
		{
			ft_rev_rotate_a(head_b);
			pos++;
		}
	}
	ft_push_a(head_a, head_b);
}

void	ft_pusher(t_list **head_a, t_list **head_b, int value)
{
	int	pos;
	int	size;

	pos = ft_get_pos(head_a, value);
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

int	ft_get_pos(t_list **head, int value)
{
	t_list	*tmp;
	int		pos;

	pos = 1;
	tmp = (*head);
	while (tmp->content != value)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}


void	ft_get_final_pos(t_list **head, int i)
{
	t_list	*tmp;
	int		current;

	tmp = (*head);
	while (tmp->pos)
		tmp = tmp->next;
	current = tmp->content;
	tmp = tmp->next;
	while (tmp)
	{
		if (current > tmp->content && !tmp->pos)
			current = tmp->content;
		tmp = tmp->next;
	}
	tmp = (*head);
	while (tmp->content != current)
		tmp = tmp->next;
	tmp->pos = i;
}
