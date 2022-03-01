/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:02:33 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/01 16:23:56 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int hits = 0;

void	printer(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	t_list	*sec;

	tmp = (*head_a);
	sec = (*head_b);
	printf("\nstack A\n--------|\n");
	while (tmp)
	{
		printf("  %i\t| pos: %d \n", tmp->content, tmp->pos);
		tmp = tmp->next;
	}
	printf("--------|\n");
	printf("\nstack B\n--------|\n");
	while (sec)
	{
		printf("  %i\t| pos: %d\n", sec->content, sec->pos);
		sec = sec->next;
	}
	printf("--------|\n");
	printf("total hits: %d\n\n\n", hits);
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

	if (!ft_check_args(av))
		ft_err();
	b = NULL;
	a = ft_init_stack(av, ac);
	head_a = &a;
	head_b = &b;
	printer(head_a, head_b);
	if (ac - 1 <= 3)
		ft_lil_sort(head_a);
	else if (ac - 1 > 3)
		ft_sort(head_a, head_b);
	printer(head_a, head_b);
	ft_lstfree(head_a, head_b);
	return (0);
}
