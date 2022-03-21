/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:32:03 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/21 19:36:34 by chaidel          ###   ########.fr       */
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
	if (ft_is_sorted(head_a))
		return ;
	while (piv.old_pivot > 0)
	{
		ft_select(head_a, head_b, &piv);
		piv.old_pivot = piv.pivot;
		piv.iter++;
	}
}

void	ft_select(t_list **head_a, t_list **head_b, t_lim *piv)
{
	int		size;
	t_list	*tmp;

	size = ft_lstsize((*head_a));
	if (size <= 100)
		piv->pivot = size - (size / 5) * piv->iter;
	else
		piv->pivot = size - (size / 10) * piv->iter;
	tmp = (*head_a);
	while (tmp)
	{
		if (tmp->pos > piv->pivot && tmp->pos <= piv->old_pivot)
		{
			ft_pusher(head_a, head_b, tmp->content);
			tmp = (*head_a);
		}
		else
			tmp = tmp->next;
	}
	if (piv->iter > 1)
		ft_prep(head_a, piv);
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
			ft_rotate_b(head_b);
			pos--;
		}
	}
	else
	{
		while (pos <= size && size > 1)
		{
			ft_rev_rotate_b(head_b);
			pos++;
		}
	}
	ft_push_a(head_a, head_b);
}

/*
				Preparer la stack A a recvoir les blocs trier depuis B
				(Debute apres la 1ere iteration)
	------------------------------------------------------------------
	Objectif ->	Trouve la value avec une pos egale au old_pivot
				Rotate la stack A pour que la dite value soit en pole position
				Enfin le bloc trier depuis B est push dans A
*/

void	ft_prep(t_list **head_a, t_lim *piv)
{
	int		pos;
	int		size;
	t_list	*tmp;

	tmp = (*head_a);
	while (tmp->pos != piv->old_pivot + 1)
		tmp = tmp->next;
	pos = ft_get_pos(head_a, tmp->content);
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
