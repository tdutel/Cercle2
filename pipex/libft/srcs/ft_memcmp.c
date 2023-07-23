/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:51:32 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:46:16 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ps1;
	char	*ps2;

	ps1 = (char *)s1;
	ps2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ps1[i] == ps2[i] && (i < n - 1))
	{
		i++;
	}
	if (ps1[i] == ps2[i])
	{
		return (0);
	}
	return ((unsigned char)ps1[i] - (unsigned char)ps2[i]);
}
