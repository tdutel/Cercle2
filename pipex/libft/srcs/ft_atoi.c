/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:02:40 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:44:59 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	sign;
	size_t	convert;

	sign = 1;
	convert = 0;
	i = 0;
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= (-1);
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			convert = convert * 10 + str[i] - 48;
			i++;
		}
		return (sign * convert);
	}
	return (0);
}
