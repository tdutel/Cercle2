/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:24:01 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/16 13:50:47 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long int	ft_atoi_long(const char *str)
{
	long long int	i;
	long long int	sign;
	long long int	convert;

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
