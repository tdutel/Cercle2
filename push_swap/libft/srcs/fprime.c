/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:23:42 by tdutel            #+#    #+#             */
/*   Updated: 2023/02/15 15:33:02 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	recu(int nb, int n)
{
	while (nb > 1)
	{
		if (nb % n == 0)
		{
			if (nb > 1)
				ft_printf("%d", n);
			nb = nb / n;
			if (nb > 1)
				ft_printf("*");
		}
		else
			n++;
	}
}

int	fprime(char *num)
{
	int	nb;

	if (!num)
	{
		ft_printf("\n");
		return (0);
	}
	nb = ft_atoi(num);
	if (nb == 1)
	{
		ft_printf("1\n");
		return (0);
	}
	recu(nb, 2);
	ft_printf("\n");
	return (0);
}
