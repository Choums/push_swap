/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:02:33 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/11 12:31:11 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printer(t_list **head_a, t_list **head_b)
{
	printf("\nstack A\n--------\n");
	while ((*head_a))
	{
		printf("%s\n", (*head_a)->content);
		(*head_a) = (*head_a)->next;
	}
	printf("--------\n");
	printf("\nstack B\n--------\n");
	while ((*head_b))
	{
		printf("%s\n", (*head_b)->content);
		(*head_b) = (*head_b)->next;
	}
	printf("--------\n");
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	**head_a;
	t_list	**head_b;

	head_a = &a;
	head_b = &b;
	if (!ft_check_args(av))
	{
		ft_putstr_fd(ERR, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	b = NULL;
	a = ft_init_stack(av, ac);

	ft_rotate_a(head_a);

	printer(head_a, head_b);

	return (0);
}
