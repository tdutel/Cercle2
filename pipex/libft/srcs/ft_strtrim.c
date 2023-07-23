/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:37:00 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:47:24 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	is_blank(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_is_in_set(s1[i], set) == 1)
		i++;
	if (s1[i] == '\0')
		return (-1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		c;
	char	*new;

	i = 0;
	c = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	j = ft_strlen(s1);
	if (is_blank(s1, set) == -1)
		return (ft_strdup(""));
	while (ft_is_in_set(s1[i], set) == 1 && ++c)
		i++;
	while (j >= 0 && ft_is_in_set(s1[--j], set) == 1)
		c++;
	new = malloc(sizeof(*new) * (ft_strlen(s1) - c + 1));
	if (!new)
		return (NULL);
	c = 0;
	while (i <= j)
		new[c++] = s1[i++];
	new[c] = '\0';
	return (new);
}
