/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:14:12 by tdutel            #+#    #+#             */
/*   Updated: 2023/03/21 14:43:56 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{

	if ((*a)->next != NULL && (*a)->next->next == NULL)
		if ((*a)->content > (*a)->next->content)
			return (ft_sa(*a));
	if (is_sorted(*a) == 1)
		return ;
	if (ft_stcksize(*a) < 60)
		return (quick_sort(a, b));
	else
		return (long_sort_manager(a, b));
}

void	quick_sort(t_stack **a, t_stack **b)
{
	int	min;

	while ((*a)->next->next->next != NULL )
	{
		min = get_min(*a);
		while (min != (*a)->content)
		{
			if (ft_stcksize_to(*a, min) == 1)
				ft_ra(a);
			else
				ft_rra(a);
		}
		if (is_sorted(*a) == 1)
			break ;
		ft_pb(a, b);
	}
	if (!(is_sorted(*a) == 1))
		triple_sort(a);
	while ((*b) != NULL)
		ft_pa(a, b);
}

void	triple_sort(t_stack **a)
{
	if (sorted_or_revsorted(a) == 1)
		return ;
	else if ((*a)->content < (*a)->next->content
		&& (*a)->content < (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		ft_rra(a);
		ft_sa(*a);
	}
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content < (*a)->next->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		ft_sa(*a);
	else if ((*a)->content < (*a)->next->content
		&& (*a)->content > (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
		ft_rra(a);
	else if (sorted_or_revsorted(a) == -1)
	{
		ft_ra(a);
		ft_sa(*a);
	}
	else
		ft_ra(a);
}
