/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:37:27 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/12 08:52:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_args(char **av)
{
	size_t	i;
	size_t	s;

	i = 0;
	while (av[++i])
	{
		s = -1;
		while (av[i][++s])
		{
			if (!ft_isdigit(av[i][s]))
				return (0);
			if (av[i][s] == '0' && av[i][s + 1] == '0')
				return (0);
		}
		if (!ft_check_dup(av, av[i], i))
			return (0);
	}
	return (1);
}

int	ft_check_dup(char **av, char *num, size_t pos)
{
	size_t	i;

	i = 0;
	while (av[++i] && i < pos)
		if (!ft_strcmp(av[i], num))
			return (0);
	return (1);
}

void	ft_lstfree(t_list **head_a, t_list **head_b)
{
	ft_lstclear(head_a, ft_del);
	ft_lstclear(head_b, ft_del);
}
void	ft_print(char *msg)
{
	ft_putstr_fd(msg, STDOUT_FILENO);
}

void	ft_err(void)
{
	ft_putstr_fd(ERR, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}
