/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:54:57 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:46:34 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

ssize_t	xft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	xft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(fd, s, xft_strlen(s)));
}

ssize_t	xft_putnbr_fd(int n, int fd)
{
	size_t	r;

	r = 0;
	if (n <= -2147483648)
	{
		r += xft_putstr_fd("-2", fd);
		n = 147483648;
	}
	if (n >= 0 && n <= 9)
		r += xft_putchar_fd(n + '0', fd);
	else
	{
		if (n < 0)
		{
			r += xft_putchar_fd('-', fd);
			r += xft_putnbr_fd(n * (-1), fd);
		}
		else
		{
			r += xft_putnbr_fd(n / 10, fd);
			r += xft_putnbr_fd(n % 10, fd);
		}
	}
	return (r);
}

ssize_t	xft_putunsigned_fd(unsigned int n, int fd)
{
	size_t	r;

	r = 0;
	if (n >= 0 && n <= 9)
		r += xft_putchar_fd(n + '0', fd);
	else
	{
		r += xft_putnbr_fd(n / 10, fd);
		r += xft_putnbr_fd(n % 10, fd);
	}
	return (r);
}
