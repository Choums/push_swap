/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:02:36 by chaidel           #+#    #+#             */
/*   Updated: 2022/01/24 18:38:32 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // A supp.
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"
# define ERR "Error\n"

int		ft_check_args(char **av);
int		ft_check_dup(char **av, char *num, size_t pos);
void	ft_err(void);

void	ft_print(char *msg);
t_list	*ft_init_stack(char **value, int size);
void	ft_swap_a(t_list *a);

#endif
