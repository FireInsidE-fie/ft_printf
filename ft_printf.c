/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:57:28 by estettle          #+#    #+#             */
/*   Updated: 2024/10/27 21:07:21 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_conversion(char c, int *count, va_list args)
{
	if (c == 'c' && ++(*count))
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		process_str(va_arg(args, char *), count);
	else if (c == 'p')
		process_ptr(va_arg(args, void *), count);
	else if (c == 'd' || c == 'i')
		process_dec(va_arg(args, int), count);
	else if (c == 'u')
		process_uns(va_arg(args, unsigned int), count);
	else if (c == 'x')
		process_hex(va_arg(args, unsigned int), count, 0);
	else if (c == 'X')
		process_hex(va_arg(args, unsigned int), count, 1);
	else if (c == '%' && ++(*count))
		write(1, "%", 1);
	else if (++(*count))
		write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				process_conversion(format[i++], &count, args);
		}
		else if (format[i])
		{
			write(1, format + i++, 1);
			count++;
		}
	}
	return (count);
}
