/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:44:36 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:46:26 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	index_control(const char *fmt, size_t *i, va_list ap)
{
	size_t	r;

	if (fmt[*i + 1] == 'c')
		r = xft_putchar_fd(va_arg(ap, int), 1);
	else if (fmt[*i + 1] == 's')
		r = xft_putstr_fd(va_arg(ap, char *), 1);
	else if (fmt[*i + 1] == 'p')
		r = ft_putptr_fd(va_arg(ap, size_t), 1);
	else if (fmt[*i + 1] == 'd' || fmt[*i + 1] == 'i')
		r = xft_putnbr_fd(va_arg(ap, int), 1);
	else if (fmt[*i + 1] == 'u')
		r = xft_putunsigned_fd(va_arg(ap, unsigned int), 1);
	else if (fmt[*i + 1] == 'x')
		r = ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789abcdef", 1);
	else if (fmt[*i + 1] == 'X')
		r = ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", 1);
	else if (fmt[*i + 1] == '%')
		r = xft_putchar_fd('%', 1);
	else
		r = xft_putchar_fd(fmt[*i + 1], 1);
	*i += 1;
	return (r);
}

static int	ft_checkconv(const char *ft)
{
	if (ft[0] == '%')
	{
		if ((ft[1] != 'c') && (ft[1] != 's') && (ft[1] != 'p') \
		&& (ft[1] != 'd') && (ft[1] != 'i') && (ft[1] != 'u') \
		&& (ft[1] != 'x') && (ft[1] != 'X') && (ft[1] != '%'))
			return (-1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	ap;
	size_t	ret;
	ssize_t	tmp;

	ret = 0;
	va_start(ap, format);
	i = 0;
	if (ft_checkconv(format) == -1)
		return (0);
	while (format[i])
	{
		if (write(1, 0, 0) == -1)
			return (-1);
		if (format[i] == '%')
			tmp = index_control(format, &i, ap);
		else
			tmp = xft_putchar_fd(format[i], 1);
		i++;
		if (tmp < 0)
			return (-1);
		ret += tmp;
	}
	va_end(ap);
	return (ret);
}
