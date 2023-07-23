/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:58:09 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:47:46 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_is_nl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE];
	char		*stck;
	int			k;

	k = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	stck = gnl_strjoin(NULL, buf[fd]);
	while (ft_is_nl(stck) == -1)
	{
		k = read(fd, buf[fd], BUFFER_SIZE);
		if (k > 0)
			buf[fd][k] = '\0';
		else
		{
			buf[fd][0] = '\0';
			return (ft_read_error(stck, k));
		}
		stck = gnl_strjoin(stck, buf[fd]);
	}
	stck = ft_strdupcpy(stck, ft_is_nl(stck) + 1);
	ft_alter_buffer(buf[fd], ft_is_nl(buf[fd]) + 1);
	return (stck);
}

char	*ft_alter_buffer(char buf[BUFFER_SIZE], int k)
{
	int	j;

	j = 0;
	while (j < BUFFER_SIZE - k)
	{
		buf[j] = buf[k + j];
		j++;
	}
	gnl_bzero(buf, j, BUFFER_SIZE);
	return (buf);
}

void	gnl_bzero(char buf[BUFFER_SIZE], size_t n, size_t size)
{
	size_t	i;

	i = 0;
	while (i < n)
		i++;
	while (i < size)
	{
		buf[i] = '\0';
		i++;
	}
}

char	*ft_read_error(char *stck, int k)
{
	if (k < 0)
		return (ft_free_process(stck, NULL));
	else
		return (stck);
}
