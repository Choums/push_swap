/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:35:45 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/21 21:46:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	while (tmp->pos && )
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

void	ft_init_pivot(int size, t_lim *piv)
{
	piv->iter = 1;
	piv->old_pivot = size;
}
