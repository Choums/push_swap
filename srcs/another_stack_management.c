/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_stack_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:25:18 by root              #+#    #+#             */
/*   Updated: 2022/03/22 20:08:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate_a(t_list **head_a, int db)
{
	t_list	*tmp;
	int		swap;
	int		fpos;
	int		size;

	if (!(*head_a))
		return ;
	tmp = (*head_a);
	size = ft_lstsize((*head_a));
	while (size - 1 > 0)
	{
		swap = tmp->next->content;
		fpos = tmp->next->pos;
		tmp->next->content = tmp->content;
		tmp->next->pos = tmp->pos;
		tmp->content = swap;
		tmp->pos = fpos;
		tmp = tmp->next;
		size--;
	}
	if (!db)
		ft_print(RA);
}

void	ft_rotate_b(t_list **head_b, int db)
{
	t_list	*tmp;
	int		swap;
	int		fpos;
	int		size;

	tmp = (*head_b);
	size = ft_lstsize((*head_b));
	while (size - 1)
	{
		swap = tmp->next->content;
		fpos = tmp->next->pos;
		tmp->next->content = tmp->content;
		tmp->next->pos = tmp->pos;
		tmp->content = swap;
		tmp->pos = fpos;
		tmp = tmp->next;
		size--;
	}
	if (!db)
		ft_print(RB);
}

void	ft_rotate_rr(t_list **head_a, t_list **head_b)
{
	ft_rotate_a(head_a, 1);
	ft_rotate_b(head_b, 1);
	ft_print(RR);
}

void	ft_rev_rotate_a(t_list **head_a, int db)
{
	t_list	*tmp;
	int		swap;
	int		fpos;
	int		size;

	if (!(*head_a))
		return ;
	tmp = ft_lstlast((*head_a));
	size = ft_lstsize((*head_a));
	while (size - 1 > 0)
	{
		swap = tmp->previous->content;
		fpos = tmp->previous->pos;
		tmp->previous->content = tmp->content;
		tmp->previous->pos = tmp->pos;
		tmp->content = swap;
		tmp->pos = fpos;
		tmp = tmp->previous;
		size--;
	}
	if (!db)
		ft_print(RRA);
}

void	ft_rev_rotate_b(t_list **head_b, int db)
{
	t_list	*tmp;
	int		swap;
	int		fpos;
	int		size;

	if (!(*head_b))
		return ;
	tmp = ft_lstlast((*head_b));
	size = ft_lstsize((*head_b));
	while (size - 1 > 0)
	{
		swap = tmp->previous->content;
		fpos = tmp->previous->pos;
		tmp->previous->content = tmp->content;
		tmp->previous->pos = tmp->pos;
		tmp->content = swap;
		tmp->pos = fpos;
		tmp = tmp->previous;
		size--;
	}
	if (!db)
		ft_print(RRB);
}
