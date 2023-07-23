/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:58:27 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 14:33:50 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_is_nl(char *s);
char	*ft_alter_buffer(char buf[BUFFER_SIZE], int k);
void	gnl_bzero(char buf[BUFFER_SIZE], size_t n, size_t size);
char	*ft_read_error(char *stck, int k);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(char *str);
char	*ft_strdupcpy(char *src, size_t destsize);
char	*gnl_strdup(char *src);
char	*ft_free_process(char *to_free, char *to_return);

#endif
