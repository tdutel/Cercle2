/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:37:46 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:47:03 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;	

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[i] && i < dstsize)
		i++;
	j = 0;
	while (i + j + 1 < dstsize && src[j])
	{
		dst[i + j] = src [j];
		j++;
	}
	if (i + j < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
