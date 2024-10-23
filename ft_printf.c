/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:57:28 by estettle          #+#    #+#             */
/*   Updated: 2024/10/19 23:58:03 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_conversion(char c, va_list args)
{
	if (c == 'c')
		write(1, va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		ft_print_addr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putuns(va_arg(args, unsigned int));
	else if (c == 'x')
		ft_puthex(va_arg(args, int), 0);
	else if (c == 'X')
		ft_puthex(va_arg(args, int), 1);
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
int ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*(format) == '%') // careful, I'm not sure if format doesn't get incremented BEFORE dereferencing
			process_conversion(*(format++), args);
		write(1, format++, 1);
	}
	return (0);
}
