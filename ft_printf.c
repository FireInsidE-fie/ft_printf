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
	if (nb == -2147483648)
	{
		write(1, "-80000000", 9);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
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
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
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
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		count++;
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				process_conversion(format[i++], args);
		}
		if (format[i])
			write(1, format + i++, 1);
	}
	return (count);
}
