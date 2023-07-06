/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:26:58 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/08 20:43:42 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	printf_format(const char *format, int i, va_list arg_ptr)
{
	if (format[i + 1] == '%')
		return (md_putchar(format[i + 1]));
	else if (format[i + 1] == 'c')
		return (md_putchar(va_arg(arg_ptr, int)));
	else if (format[i + 1] == 's')
		return (md_putstr(va_arg(arg_ptr, char *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (md_putnbr(va_arg(arg_ptr, int)));
	else if (format[i + 1] == 'x')
		return (md_puthex(va_arg(arg_ptr, unsigned int), 'x'));
	else if (format[i + 1] == 'X')
		return (md_puthex(va_arg(arg_ptr, unsigned int), 'X'));
	else if (format[i + 1] == 'p')
		return (md_puthex(va_arg(arg_ptr, unsigned long), 'p'));
	else if (format[i + 1] == 'u')
		return (md_unsigned_putnbr(va_arg(arg_ptr, unsigned int)));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		num_char_printed;
	int		i;

	i = -1;
	va_start (arg_ptr, format);
	num_char_printed = 0;
	while (format[++i])
	{
		if (format[i] == '%' && ft_strchr(FLAGS, format[i + 1]))
			num_char_printed += printf_format(format, i++, arg_ptr);
		else
			num_char_printed += md_putchar(format[i]);
	}
	va_end(arg_ptr);
	return (num_char_printed);
}
