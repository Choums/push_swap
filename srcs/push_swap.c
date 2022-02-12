/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:02:33 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/12 15:13:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printer(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	t_list	*sec;
	
	tmp = (*head_a);
	sec = (*head_b);
	printf("\nstack A\n--------\n");
	while (tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	printf("--------\n");
	printf("\nstack B\n--------\n");
	while (sec)
	{
		printf("%s\n", sec->content);
		sec = sec->next;
	}
	printf("--------\n");
}

void	ft_del(void *content)
{
	content = NULL;
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

	b = NULL;
	a = ft_init_stack(av, ac);
	head_a = &a;
	head_b = &b;
	if (!ft_check_args(av))
	{
		ft_putstr_fd(ERR, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
		
	printer(head_a, head_b);
	ft_push_b(head_a, head_b);
	ft_push_b(head_a, head_b);
	ft_push_b(head_a, head_b);
	ft_push_b(head_a, head_b);
	printer(head_a, head_b);
	ft_rev_rotate_b(head_b);

	printer(head_a, head_b);
	
	ft_lstfree(head_a, head_b);
	return (0);
}
