/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:48:52 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/16 13:45:51 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stcklast(t_stack *stck)
{
	if (!stck)
		return (NULL);
	while (stck->next)
		stck = stck->next;
	return (stck);
}

int	ft_stcksize(t_stack *stck)
{
	int	i;

	i = 0;
	if (!stck)
		return (0);
	while (stck != NULL)
	{
		stck = stck->next;
		i++;
	}
	return (i);
}

int	ft_stcksize_to(t_stack *stck, int cont)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!stck)
		return (0);
	while (stck && stck->content != cont)
	{
		stck = stck->next;
		i++;
	}
	while (stck)
	{
		stck = stck->next;
		j++;
	}
	if (i <= j)
		return (1);
	else
		return (2);
}
