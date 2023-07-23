/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:01:15 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/11 12:17:12 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sa(t_stack *a)
{
	if (a == NULL)
		return ;
	else if (a->next == NULL)
		return ;
	ft_swap_int(&a->content, &a->next->content);
	ft_printf("sa\n");
}

void	ft_sb(t_stack *b)
{
	if (b == NULL)
		return ;
	else if (b->next == NULL)
		return ;
	ft_swap_int(&b->content, &b->next->content);
	ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	if (a != NULL && a->next != NULL)
		ft_swap_int(&a->content, &a->next->content);
	if (b != NULL && b->next != NULL)
		ft_swap_int(&b->content, &b->next->content);
	ft_printf("ss\n");
}
