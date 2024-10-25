/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:57:28 by estettle          #+#    #+#             */
/*   Updated: 2024/10/25 14:40:26 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuns(unsigned int n)
{
	if (n >= 10)
	{
		ft_putuns(n / 10);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
}

static void	process_conversion(char c, int *count, va_list args)
{
	if (c == 'c' && ++(*count))
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		process_string(va_arg(args, char *), count);
	else if (c == 'p')
		;
		//ft_print_addr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		process_decimal(va_arg(args, int), count);
	else if (c == 'u')
		ft_putuns(va_arg(args, unsigned int));
	else if (c == 'x')
		; //ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		; //ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
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
