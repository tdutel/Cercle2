/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:41:34 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/16 13:50:08 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	long_sort_manager(t_stack **a, t_stack **b)
{
	index_stack(a);
	radix_sort(a, b);
}

int	get_index(t_stack *stack, int value)
{
	int	idx;

	idx = 0;
	while (stack)
	{
		if (stack->content < value)
			idx++;
		stack = stack->next;
	}
	return (idx);
}

void	index_stack(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (*stack)
	{
		(*stack)->index = get_index(head, ((*stack)->content));
		*stack = (*stack)->next;
	}
	*stack = head;
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	max;
	int	size;

	i = 0;
	max = sizeof(int) * 8 - 1;
	while (i < max)
	{
		if (ind_sorted(*a) == 1)
			return ;
		size = ft_stcksize(*a);
		while (size--)
		{
			if (((*a)->index >> i) & 1)
				ft_ra(a);
			else
				ft_pb(a, b);
		}
		while (*b != NULL)
			ft_pa(a, b);
		i++;
	}
}
