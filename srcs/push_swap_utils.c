/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:37:27 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/01 10:11:34 by chaidel          ###   ########.fr       */
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
		s = 0;
		if (av[i][s] == '-' || av[i][s] == '+')
			if (!av[i][++s])
				return (0);
		while (av[i][s])
		{
			if (!ft_isdigit(av[i][s]))
				return (0);
			if (av[i][0] == '0' && av[i][1] == '0')
				return (0);
			s++;
		}
		if (ft_strlen(av[i]) > 2 && (ft_atoi(av[i]) == -1 || !ft_atoi(av[i])))
			return (0);
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

t_list	*ft_init_stack(char **value, int size)
{
	size_t	i;
	t_list	*tmp;

	i = 1;
	tmp = ft_lstnew(ft_atoi(value[i]));
	if (!tmp)
		ft_err();
	while (++i <= (size_t)size - 1)
	{
		ft_lstadd_back(&tmp, ft_lstnew(ft_atoi(value[i])));
		if (!tmp)
			ft_err();
	}
	return (tmp);
}

void	ft_print(char *msg)
{
	ft_putstr_fd(msg, STDOUT_FILENO);
}

void	ft_err(void)
{
	ft_putstr_fd(ERR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
