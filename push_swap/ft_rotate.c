/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:18:16 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/11 12:34:25 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stck)
{
	t_stack	*tmp;
	t_stack	*cursor;

	if (*stck == NULL)
		return ;
	else if ((*stck)->next == NULL)
		return ;
	tmp = *stck;
	*stck = (*stck)->next;
	tmp->next = NULL;
	cursor = *stck;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = tmp;
}

void	ft_ra(t_stack **stck_a)
{
	ft_rotate(stck_a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **stck_b)
{
	ft_rotate(stck_b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **stck_a, t_stack **stck_b)
{
	ft_rotate(stck_a);
	ft_rotate(stck_b);
	ft_printf("rr\n");
}
