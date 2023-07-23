/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:04:16 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/12 14:25:47 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stck_a)
{
	t_stack	*tmp;
	t_stack	*prev;

	prev = *stck_a;
	tmp = *stck_a;
	while ((*stck_a)->next)
	{
		prev = *stck_a;
		*stck_a = (*stck_a)->next;
		prev->next = *stck_a;
	}
	(*stck_a)->next = tmp;
	prev->next = NULL;
}

void	rrb(t_stack **stck_b)
{
	t_stack	*tmp;
	t_stack	*prev;

	prev = *stck_b;
	tmp = *stck_b;
	while ((*stck_b)->next)
	{
		prev = *stck_b;
		*stck_b = (*stck_b)->next;
		prev->next = *stck_b;
	}
	(*stck_b)->next = tmp;
	prev->next = NULL;
}

void	ft_rra(t_stack **stck_a)
{
	rra(stck_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **stck_b)
{
	rrb(stck_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **stck_a, t_stack **stck_b)
{
	rra(stck_a);
	rrb(stck_b);
	ft_printf("rrr\n");
}
