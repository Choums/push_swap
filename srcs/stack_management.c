/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:37:38 by chaidel           #+#    #+#             */
/*   Updated: 2022/01/24 18:38:54 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_init_stack(char **value, int size)
{
	size_t	i;
	t_list	*tmp;

	i = 1;
	tmp = ft_lstnew(value[i]);
	if (!tmp)
		ft_err();
	while (++i <= (size_t)size)
	{
		ft_lstadd_back(&tmp, ft_lstnew(value[i]));
		if (!tmp)
			ft_err();
	}
	return (tmp);
}

void	ft_swap_a(t_list *a)
{
	char	*tmp;

	if (!a->content || !a->next->content)
		return ;
	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
	ft_print(SA);
}

void	ft_swap_b(t_list *b)
{
	char	*tmp;

	if (!b->content || !b->next->content)
		return ;
	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
	ft_print(SB);
}

void	ft_swap_ss(t_list *a, t_list *b)
{
	ft_swap_a(a);
	ft_swap_b(b);
}