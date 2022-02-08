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

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
<<<<<<< HEAD
    
    return (0);
}
=======
	t_list	*a;
	t_list	*b;

	if (!ft_check_args(av))
	{
		ft_putstr_fd(ERR, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	b = ft_lstnew(NULL);
	a = ft_init_stack(av, ac);

	ft_swap_a(a);

	for (int i = 0; i < ac; i++)
	{
		printf("%s\n", a->content);
		a = a->next;
	}
	return (0);
}
>>>>>>> d61f3f0d86a901f03617aeb523303d8b1f74f67f
