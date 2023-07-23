/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:37:20 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/11 12:39:46 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **stck_a, t_stack **stck_b)
{
	t_stack	*tmp;

	if (*stck_b == NULL)
		return ;
	tmp = (*stck_b)->next;
	(*stck_b)->next = *stck_a;
	*stck_a = *stck_b;
	*stck_b = tmp;
	ft_printf("pa\n");
}

void	ft_pb(t_stack **stck_a, t_stack **stck_b)
{
	t_stack	*tmp;

	if (*stck_a == NULL)
		return ;
	tmp = (*stck_a)->next;
	(*stck_a)->next = *stck_b;
	*stck_b = *stck_a;
	*stck_a = tmp;
	ft_printf("pb\n");
}
