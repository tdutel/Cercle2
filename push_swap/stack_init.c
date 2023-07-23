/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:55 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/12 13:49:31 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_intstack_new(int content)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

void	ft_int_add_front(t_stack **stck, t_stack *new)
{
	if (stck && new)
	{
		new->next = *stck;
		*stck = new;
	}
}

void	ft_int_add_back(t_stack **stck, t_stack *new)
{
	t_stack	*tmp;

	if (stck)
	{
		if (*stck == NULL)
			*stck = new;
		else
		{
			tmp = ft_stcklast(*(stck));
			tmp->next = new;
		}
	}
}
