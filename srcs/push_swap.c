/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:02:33 by chaidel           #+#    #+#             */
/*   Updated: 2022/01/24 18:39:03 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list  **head_a;
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

	ft_push_b(head_a, head_b);
	ft_push_b(head_a, head_b);
	printf("stack A\n-----\n");
	while (a)
	{
		printf("%s\n", a->content);
		a = a->next;
	}
	printf("\nstack B\n-----\n");
	while (b)
	{
		printf("%s\n", b->content);
		b = b->next;
	}
	return (0);
}