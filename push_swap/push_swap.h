/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:51:26 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/17 11:23:57 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				index;
}					t_stack;

//check_main.c
int		error_check(int argc, char **argv);
int		ft_is_already_in(char **argv);
int		ft_isdigit_space(char *str);
int		is_in(t_stack *a, int nb);
int		ft_int_list(char *list, t_stack **a);

//stack_init.c
t_stack	*ft_intstack_new(int content);
void	ft_int_add_front(t_stack **stck, t_stack *new);
void	ft_int_add_back(t_stack **stck, t_stack *new);

//stack_tools.c
t_stack	*ft_stcklast(t_stack *stck);
int		ft_stcksize(t_stack *stck);
int		ft_stcksize_to(t_stack *stck, int cont);

//ft_swap.c
void	ft_swap_int(int *a, int *b);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);

//ft_push.c
void	ft_pa(t_stack **stck_a, t_stack **stck_b);
void	ft_pb(t_stack **stck_a, t_stack **stck_b);

//ft_rotate.c
void	ft_rotate(t_stack **stck);
void	ft_ra(t_stack **stck_a);
void	ft_rb(t_stack **stck_b);
void	ft_rr(t_stack **stck_a, t_stack **stck_b);

//ft_reverse.c
void	rra(t_stack **stck_a);
void	rrb(t_stack **stck_b);
void	ft_rra(t_stack **stck_a);
void	ft_rrb(t_stack **stck_b);
void	ft_rrr(t_stack **stck_a, t_stack **stck_b);

//sort_tab.c
void	ft_sort(t_stack **a, t_stack **b);
void	quick_sort(t_stack **a, t_stack **b);
void	triple_sort(t_stack **a);

//sort_tools.c
int		is_sorted(t_stack *a);
int		ind_sorted(t_stack *a);
int		sorted_or_revsorted(t_stack **a);
int		get_min(t_stack *a);

//radix_sort.c
void	long_sort_manager(t_stack **a, t_stack **b);
int		get_index(t_stack *stack, int value);
void	index_stack(t_stack **stack);
void	radix_sort(t_stack **a, t_stack **b);

//free_process.c
int		free_stack(t_stack *stck);
int		free_stack_exit(t_stack *stck);

#endif
