/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:51:38 by tdutel            #+#    #+#             */
/*   Updated: 2023/03/21 14:43:29 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		arc;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (error_check(argc, argv) == 1)
		return (0);
	if (argc > 2)
	{
		arc = argc - 1;
		a = NULL;
		while (arc > 0)
			ft_int_add_front(&a, ft_intstack_new(ft_atoi_long(argv[arc--])));
	}
	else if (ft_int_list(argv[1], &a) == 0)
		return (ft_putendl_fd("Error", STDERR_FILENO), 0);
	b = NULL;
	ft_sort(&a, &b);
	return (free_stack(a));
}
