/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:53:40 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:46:45 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_in_char(char const *s, char c, size_t i)
{
	if (s[i] != c)
	{
		if (s[i + 1] == c || s[i + 1] == '\0')
		{
			return (1);
		}
	}
	return (0);
}

static int	ft_len_set(char const *s, char c, size_t i)
{
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	**ft_procedure(char **new)
{
	size_t	a;

	a = -1;
	while (new[++a])
		free(new[a]);
	free(new);
	return (NULL);
}

static char	**ft_splitnwrite(char **new, char const *s, char c, size_t nbr)
{
	size_t		j;
	size_t		i;
	size_t		len;

	i = 0;
	while (i < nbr)
	{
		while (s[0] == c)
			s++;
		len = ft_len_set(s, c, 0);
		new[i] = malloc(sizeof(char) * (len + 1));
		if (!new[i])
			return (ft_procedure(new));
		j = 0;
		while (j < len)
			new[i][j++] = *s++;
		new[i][j] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char		**new;
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		count += ft_in_char(s, c, i);
		i++;
	}
	new = malloc(sizeof(*new) * (count + 1));
	if (!new)
		return (NULL);
	return (ft_splitnwrite(new, s, c, count));
}
