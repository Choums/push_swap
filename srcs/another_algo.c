/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:32:03 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/01 19:55:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_list **head_a, t_list **head_b)
{
	int		i;
	int		size;
	t_lim	piv;
	
	size = ft_lstsize((*head_a));
	ft_init_pivot(size, &piv);
	i = 0;
	while (++i <= size)
		ft_get_final_pos(head_a, i);

	while (piv.pivot >= 0)
	{
		ft_select(head_a, head_b, &piv);
		piv.old_pivot = piv.pivot;
		piv.iter++;
	}
}

void	ft_init_pivot(int size, t_lim *piv)
{
	piv->iter = 1;
	piv->old_pivot = size;
}

void	ft_select(t_list **head_a, t_list **head_b, t_lim *piv)
{
	int		size;
	t_list	*tmp;

	size = ft_lstsize((*head_a));
	if (size <= 100)
		piv->pivot = size - (size / 5 ) * piv->iter;
	else
		piv->pivot = size - (size / 10) * piv->iter;
	tmp = (*head_a);
	while (tmp)
	{
		if (tmp->pos >= piv->pivot)
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