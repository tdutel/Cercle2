/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:51:41 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:45:07 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;

	if (size != 0 && count != (count * size) / size)
	{
		return (NULL);
	}
	if (count == 0 || size == 0)
	{
		new = malloc(size * count);
		if (new == NULL)
			return (NULL);
	}
	else
	{
		new = malloc(size * count);
		if (new == NULL)
			return (NULL);
	}
	return (ft_memset(new, 0, size * count));
}
