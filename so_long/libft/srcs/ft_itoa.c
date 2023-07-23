/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:58:45 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:45:33 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_verif(char *new, int *n)
{
	long	ln;

	ln = *n;
	if (*n < 0)
	{
		if (ln <= -2147483648)
		{
			new[0] = '-';
			new[1] = '2';
			*n = 147483648;
		}
		else
		{
			new[0] = '-';
			*n = *n * (-1);
		}
	}
	else if (*n == 0)
		new[0] = '0';
}

char	*ft_itoa(int n)
{
	char	*new;
	int		nb;
	int		i;

	i = 1;
	nb = n;
	if (nb < 0)
		i++;
	while (!(nb < 10 && nb > -10) && i++)
		nb /= 10;
	new = malloc(sizeof(*new) * (i + 1));
	if (!new)
		return (NULL);
	ft_verif(new, &n);
	new[i] = '\0';
	while (n > 0)
	{
		new[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (new);
}
