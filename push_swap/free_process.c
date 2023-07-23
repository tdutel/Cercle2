/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:59:36 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/17 11:23:38 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stack(t_stack *stck)
{
	t_stack	*tmp;

	while (stck)
	{
		tmp = stck->next;
		stck->next = NULL;
		free(stck);
		stck = tmp;
	}
	return (0);
}

int	free_stack_exit(t_stack *stck)
{
	t_stack	*tmp;

	while (stck)
	{
		tmp = stck->next;
		stck->next = NULL;
		free(stck);
		stck = tmp;
	}
	exit (0);
	return (0);
}
