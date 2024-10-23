/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:57:28 by estettle          #+#    #+#             */
/*   Updated: 2024/10/23 10:55:20 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nb, char *charset)
{
	short	base;

	base = ft_strlen(charset);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_base(nb / 10, charset);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', 1);
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

void	process_conversion(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		;
		//ft_print_addr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putuns(va_arg(args, unsigned int));
	else if (c == 'x')
		;
		//ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		;
		//ft_putnbr_base(va_arg(args, int), "0123456788ABCDEF");
	else if (c == '%')
		write(1, "%", 1);
	else
		write(1, &c, 1);
}

/* here's the plan : 
 * go through the format string character by character and print it, unless
 * there's a % in which case you go to an alternate function and begin the
 * appropriate conversion, depending on the character that occurs after the %
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*(format) == '%')
		{
			format++;
			process_conversion(*(format++), args);
		}
		write(1, format++, 1);
	}
	return (0);
}
