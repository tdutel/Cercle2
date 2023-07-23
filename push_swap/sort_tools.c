/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:15:39 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/16 13:41:43 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while ((a)->next != NULL)
	{
		if ((a)->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ind_sorted(t_stack *a)
{
	while ((a)->next != NULL)
	{
		if ((a)->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

int	sorted_or_revsorted(t_stack **a)
{
	if ((*a)->content < (*a)->next->content
		&& (*a)->content < (*a)->next->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		return (1);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
		return (-1);
	return (0);
}

int	get_min(t_stack *a)
{
	int	i;

	i = a->content;
	while (a->next != NULL)
	{
		if (i > a->next->content)
			i = a->next->content;
		a = a->next;
	}
	return (i);
}
