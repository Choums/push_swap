/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:02:36 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/23 12:30:51 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_lim
{
	int	pivot;
	int	old_pivot;
	int	iter;
}	t_lim;

void	ft_init_pivot(int size, t_lim *piv);

int		ft_check_args(char **av);
int		ft_check_dup(char **av, char *num, size_t pos);
void	ft_lstfree(t_list **head_a, t_list **head_b);
void	ft_err(void);
void	ft_print(char *msg);
t_list	*ft_init_stack(char **value, int size);

void	ft_swap_a(t_list **head_a, int db);
void	ft_swap_b(t_list **head_b, int db);
void	ft_swap_ss(t_list **head_a, t_list **head_b);

void	ft_push_a(t_list **head_a, t_list **head_b);
void	ft_push_b(t_list **head_a, t_list **head_b);

void	ft_rotate_a(t_list **head_a, int db);
void	ft_rotate_b(t_list **head_b, int db);
void	ft_rotate_rr(t_list **head_a, t_list **head_b);
void	ft_rev_rotate_a(t_list **head_a, int db);
void	ft_rev_rotate_b(t_list **head_b, int db);
void	ft_rev_rotate_rrr(t_list **head_a, t_list **head_b);

void	ft_lil_sort(t_list **head_a);
void	ft_fiv_sort(t_list **head_a, t_list **head_b);
void	ft_fiv_prep(t_list **head_a, t_list **head_b);

int		ft_get_smol(t_list **head);
int		ft_get_big(t_list **head);
int		ft_get_pos(t_list **head, int value);
void	ft_get_final_pos(t_list **head, int i);
void	ft_init_pivot(int size, t_lim *piv);

void	ft_sort(t_list **head_a, t_list **head_b);
void	ft_select(t_list **head_a, t_list **head_b, t_lim *piv);
void	ft_pusher(t_list **head_a, t_list **head_b, int value);
void	ft_prep(t_list **head_a, t_lim *piv);
void	ft_get_final_pos(t_list **head, int i);
void	ft_sortin_b(t_list **head_a, t_list **head_b);

int		ft_is_sorted(t_list **head);

#endif
