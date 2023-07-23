/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:03:04 by tdutel            #+#    #+#             */
/*   Updated: 2022/11/29 10:36:42 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	xft_strlen(const char *str);
size_t	ft_putptr_fd(size_t nbr, int fd);
ssize_t	ft_putnbr_base_fd(size_t nbr, char *base, int fd);

ssize_t	xft_putchar_fd(char c, int fd);
ssize_t	xft_putstr_fd(char *s, int fd);
ssize_t	xft_putnbr_fd(int n, int fd);
ssize_t	xft_putunsigned_fd(unsigned int n, int fd);

#endif
