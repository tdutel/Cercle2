/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:44:18 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:45:10 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	xft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_putptr_fd(size_t nbr, int fd)
{
	size_t	r;

	r = 0;
	r += xft_putstr_fd("0x", fd);
	r += ft_putnbr_base_fd(nbr, "0123456789abcdef", fd);
	return (r);
}

ssize_t	ft_putnbr_base_fd(size_t nbr, char *base, int fd)
{
	size_t	r;
	size_t	lenbase;

	r = 0;
	lenbase = xft_strlen(base);
	if (nbr >= lenbase)
		r += ft_putnbr_base_fd(nbr / lenbase, base, fd);
	r += xft_putchar_fd(base[nbr % lenbase], fd);
	return (r);
}
