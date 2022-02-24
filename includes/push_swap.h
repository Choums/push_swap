/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:02:36 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/24 13:28:42 by chaidel          ###   ########.fr       */
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
void	ft_lstfree(t_list **head_a, t_list **head_b);
void	ft_err(void);
void	ft_print(char *msg); //A supp.
t_list	*ft_init_stack(char **value, int size);

void	ft_swap_a(t_list **head_a);
void	ft_swap_b(t_list **head_b);
void	ft_swap_ss(t_list **head_a, t_list **headb);
void	ft_push_a(t_list **head_a, t_list **head_b);
void	ft_push_b(t_list **head_a, t_list **head_b);

void	ft_rotate_a(t_list **head_a);
void	ft_rotate_b(t_list **head_b);
void	ft_rotate_rr(t_list **head_a, t_list **head_b);
void	ft_rev_rotate_a(t_list **head_a);
void	ft_rev_rotate_b(t_list **head_b);

void	ft_lil_sort(t_list **head_a);

void	ft_select_sort(t_list **head_a, t_list **head_b);
void	ft_selective(t_list **head_a, t_list **head_b);
int		ft_find_smol(t_list **head);

#endif
