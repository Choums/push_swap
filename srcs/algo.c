/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 07:59:42 by root              #+#    #+#             */
/*   Updated: 2022/03/21 23:48:02 by root             ###   ########.fr       */
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

	size = ft_lstsize((*head_a));
	pos = ft_get_smol(head_a);
	if (size == 2 && (*head_a)->content > (*head_a)->next->content)
		ft_swap_a(head_a, 0);
	else if (size == 3)
	{
		if (pos == 3)
			ft_rev_rotate_a(head_a, 0);
		else if (pos == 2)
			ft_swap_a(head_a, 0);
		if ((*head_a)->next->content > (*head_a)->next->next->content)
		{
			ft_rev_rotate_a(head_a, 0);
			ft_swap_a(head_a, 0);
		}
	}
}

/*
	1-	Push 2 premier num dans B
	2-	Appliquer lil_sort sur A
	-----------------------------
	Push les num de B:
		rotate A pour que le top soit sup. au num
	Enfin rotate tout A pour aligner les nums
	(size / 2)
*/

void	ft_fiv_sort(t_list **head_a, t_list **head_b)
{
	int		size;
	int		pos;
	t_list	*tmp;
	int		i;

	size = ft_lstsize((*head_a));
	i = 0;
	while (++i <= size)
		ft_get_final_pos(head_a, i);
	if (ft_is_sorted(head_a))
		return ;
	while (size-- > 3)
		ft_fiv_prep(head_a, head_b);
	ft_lil_sort(head_a);
	while ((*head_b))
		ft_push_a(head_a, head_b);
}

void	ft_fiv_prep(t_list **head_a, t_list **head_b)
{
	int	pos;
	int	size;

	size = ft_lstsize((*head_a));
	pos = ft_get_smol(head_a);
	if (pos <= size / 2)
	{
		while (pos > 1 && size > 1)
		{
			ft_rotate_a(head_a, 0);
			pos--;
		}
	}
	else
	{
		while (pos <= size && size > 1)
		{
			ft_rev_rotate_a(head_a, 0);
			pos++;
		}
	}
	ft_push_b(head_a, head_b);
}

int	ft_get_smol(t_list **head)
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
