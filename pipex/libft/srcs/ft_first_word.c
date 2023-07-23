/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:13:29 by tdutel            #+#    #+#             */
/*   Updated: 2023/02/15 15:22:21 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_first_word(char *s)
{
	int		i;
	int		j;
	int		c;
	char	*new;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	c = 0;
	while (s[i + c] != ' ' && s[i + c] != '\t'
		&& s[i + c] != '\n' && s[i + c] != '\0')
		c++;
	j = 0;
	new = malloc (sizeof (char) * (c + 1));
	while (s[i] != ' ' && s[i] != '\t'
		&& s[i] != '\n' && s[i] != '\0')
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
