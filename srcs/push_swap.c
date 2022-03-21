/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:02:33 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/21 19:37:51 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_list **head)
{
	t_list	*tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize((*head));
	tmp = (*head);
	while (tmp && i < size - 1)
	{
		if (tmp->pos > tmp->next->pos)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	ft_del(int content)
{
	content = 0;
}

void	ft_lstfree(t_list **head_a, t_list **head_b)
{
	ft_lstclear(head_a, ft_del);
	ft_lstclear(head_b, ft_del);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	**head_a;
	t_list	**head_b;

	if (ac == 1 || !ft_check_args(av))
		ft_err();
	b = NULL;
	a = ft_init_stack(av, ac);
	head_a = &a;
	head_b = &b;
	if (ac - 1 <= 3)
		ft_lil_sort(head_a);
	else if (ac - 1 <= 5)
		ft_fiv_sort(head_a, head_b);
	else
		ft_sort(head_a, head_b);
	ft_lstfree(head_a, head_b);
	return (0);
}
