/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:57:28 by estettle          #+#    #+#             */
/*   Updated: 2024/10/25 14:06:58 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Puts a number to the standard input in the specified base.
 *
 * @param nb The number to print.
 * @param charset The charset for the base (length determines the base number).
 */
void	ft_putnbr_base(int nb, char *charset)
{
	short	base;

	base = ft_strlen(charset);
	if (nb >= base)
	{
		ft_putnbr_base(nb / base, charset);
		nb = nb % base;
	}
	if (nb < base)
		ft_putchar_fd(charset[nb], 1);
}

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
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putuns(va_arg(args, unsigned int));
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
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
