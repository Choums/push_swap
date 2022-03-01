/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:32:03 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/01 13:35:41 by chaidel          ###   ########.fr       */
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

int	ft_get_pos(t_list **head, int value)
{
	t_list *tmp;
	int pos;

	pos = 1;
	tmp = (*head);
	while (tmp->content != value)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

void	ft_pusher(t_list **head_a, t_list **head_b, int value)
{
	int	pos;
	int	size;

	size = ft_lstsize((*head_a));
	pos = ft_get_pos(head_a, value);
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


void	ft_div_sort(t_list **head_a, t_list **head_b)
{
	int		size;
	int		mid_value;
	int		mid_pos;
	int		sized;
	t_list	*tmp;
	
	size = ft_lstsize((*head_a));
	sized = size;
	mid_value = ft_org(head_a, size);
	mid_pos = ft_get_pos(head_a, mid_value);
	tmp = (*head_a);
	while (tmp && tmp->content != mid_value)
	{
		if (tmp->content < mid_value)
			ft_pusher(head_a, head_b, tmp->content);
		else
			tmp = tmp->next;
	}
	tmp = ft_lstlast((*head_a));
	while (tmp && tmp->content != mid_value)
	{
		if (tmp->content < mid_value)
			ft_pusher(head_a, head_b, tmp->content);
		else
			tmp = tmp->previous;
	}
	ft_sort_both(head_a, head_b);
}

int	ft_org(t_list **head_a, int size)
{
	int	tab[size];
	int	mid;
	int	i;
	t_list	*tmp;
	
	i = -1;
	mid = 0;
	tmp = (*head_a);
	while (++i < size)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
	}
	ft_sort_int_tab(tab, size);
	return (tab[size / 2]);
}

void    ft_sort_int_tab(int *tab, int size)
{
	int     i;
	int     s;
	int     j;

	s = 0;
	i = 0;
	while (i < (size - 1))
	{
		j = 0;
		while (j < (size - i - 1))
		{
			if (tab[j] > tab[j + 1])
			{
				s = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = s;
			}
			j++;
		}
		i++;
	}
}